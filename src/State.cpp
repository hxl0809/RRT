#include "State.hh"

State::State(){

  _x=0; _y=0; _theta=0; _delta=0; _phi=0;

}

State::State( double x, double y, double theta, double delta, double phi ){

  _x=x; _y=y; _theta=theta; _delta=delta; _phi=phi;

}

/*
State::State( const State& s ){

  _x=s.GetX(); _y=s.GetY(); _theta=s.GetTheta(); _delta=s.GetDelta(); _phi=s.GetPhi();

}
*/

State State::Set( double x, double y, double theta, double delta, double phi ){

  _x=x; _y=y; _theta=theta; _delta=delta; _phi=phi;

  return *this;

}

void State::Display(){

  printf("(%f,%f,%f,%f,%f)\n",_x,_y,_theta,_delta,_phi);

}

State State::RandomState(){

  State s;
  int bound,density;
  double x,y,theta,delta,phi;

  bound = 10;
  density = 1000;
  x = static_cast<double>(rand() % (density))*2*bound/density - bound;
  y = static_cast<double>(rand() % (density))*2*bound/density - bound;;
  theta = static_cast<double>(rand() % (density))*2*bound/density - bound;;
  delta = static_cast<double>(rand() % (density))*2*bound/density - bound;;
  phi = static_cast<double>(rand() % (density))*2*bound/density - bound;;

  s.Set(x,y,theta,delta,phi);

  return s;

}

double State::Delta( State s ){

  double delta;
  delta = sqrt( pow((_x - s.GetX()),2) + pow((_y - s.GetY()),2) );
  return delta;

}

State State::NearestNeighbor( list<State> l ){

  list<State>::iterator it;
  double minDelta;
  State neighbor;

  it = l.begin();
  minDelta = INF;

  while( it != l.end() ){

    if( Delta(*it) < minDelta ){
      neighbor = *it;
      minDelta = Delta( neighbor );
    }
    it++;

  }

  return neighbor;

}

double State::GetX(){ return _x; }
double State::GetY(){ return _y; }
double State::GetTheta(){ return _theta; }
double State::GetDelta(){ return _delta; }
double State::GetPhi(){ return _phi; }
