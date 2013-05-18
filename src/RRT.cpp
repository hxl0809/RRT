#include "RRT.hh"


RRT::RRT(){

  State *s;
  s = new State();
  _T.push_back( s );

  _outGraph = "data/graph.dot";
  _outPoints = "data/points.xy";
  _outPath = "data/path.xy";

}

RRT::~RRT(){

  _T.erase( _T.begin(), _T.end() );

}

void RRT::DisplayList(){

  list<State*>::iterator it;
  State* s;

  it = _T.begin();
  while( it != _T.end() ){

    s= *it;
    cout << "adres wierzcholka: " << s << endl;
    s->Display();
    cout << "adres rodzica " << s->GetParent() << endl;
    it++;

  }

}

void RRT::Start(){

  int maxIter = 100;
  double dt = 0.01;
  State *randomState, *nearState, *newState;
  vector<double> u;

  for( int i=0; i < maxIter; i++ ){

    randomState = new State(State::RandomState());
    nearState = randomState->NearestNeighbor( _T );
    u = Model::SelectInput( *nearState, *randomState );

    newState = new State( Model::NewState( *nearState, u, dt ) );
    newState->SetParent( nearState );
    nearState->AddSuccessor( newState );
    _T.push_back( newState );

  }


}

void RRT::SavePoints(){

  ofstream ofs;
  list<State*>::iterator it;

  ofs.open(_outPoints.c_str());
  it = _T.begin();

  while( it != _T.end() ){

    ofs << (*it)->GetX() << " " << (*it)->GetY() << endl;
    it++;

  }

}

void RRT::SaveGraph(){

  ofstream ofs;
  list<State*>::iterator it1,it2;
  list<State*> l;

  ofs.open(_outGraph.c_str());
  ofs << "digraph RRT{\n";
  it1 = _T.begin();

  while( it1 != _T.end() ){

    l = (*it1)->GetSuccessors();
    it2 = l.begin();
    while( it2 != l.end() ){

      ofs << "\"(" << (*it1)->GetX() << "," << (*it1)->GetY() << "," << (*it1)->GetTheta() << "," << (*it1)->GetDelta() << "," << (*it1)->GetPhi() << ")\" -> \"(";
      ofs << (*it2)->GetX() << "," << (*it2)->GetY() << "," << (*it2)->GetTheta() << "," << (*it2)->GetDelta() << "," << (*it2)->GetPhi() << ")\"" << endl;
      it2++;

    }
    it1++;
  }

  ofs << "}";
  ofs.close();

  system("dot -Tpng data/graph.dot > data/graph.png");


}

void RRT::SavePath(){

  list<State*>::reverse_iterator it;
  State *s;
  ofstream ofs;

  ofs.open(_outPath.c_str());

  it = _T.rbegin();
  s = *it;

  while( s->GetParent() != NULL ){

    ofs << s->GetX() << " " << s->GetY() << endl;
    //s->Display();
    s = s->GetParent();
  }

  ofs << s->GetX() << " " << s->GetY() << endl;
  //s->Display();
  ofs.close();

}
