#include "RRT.hh"


RRT::RRT(){

  State s;
  _T.push_back( s );

}

void RRT::DisplayList(){

  list<State>::iterator it;

  it = _T.begin();
  while( it != _T.end() ){

    it->Display();
    it++;

  }

}

void RRT::Start(){

  int maxIter = 300;
  double dt = 1;
  State randomState, nearState;
  vector<double> u;

  for( int i=0; i < maxIter; i++ ){

    randomState = State::RandomState();
    nearState = randomState.NearestNeighbor( _T );
    u = Model::SelectInput( nearState, randomState );
    _T.push_back( Model::NewState( nearState, u, dt ) );

  }


}

void RRT::Save(){

  ofstream ofs;
  list<State>::iterator it;

  ofs.open("data/output.dat");
  it = _T.begin();

  while( it != _T.end() ){

    ofs << it->GetX() << " " << it->GetY() << endl;
    it++;

  }



}


