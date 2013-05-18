#include "Model.hh"

Model::Model(){}

vector<double> Model::SelectInput( State s1, State s2 ){

  double u1,u2;
  vector<double> u;

  u1 = (s2.GetX() - s1.GetX())/s1.Delta(s2);
  u2 = (s2.GetY() - s1.GetY())/s1.Delta(s2);
  u.push_back(u1);
  u.push_back(u2);

  return u;

}

State Model::NewState( State s, vector<double> u, double dt ){

  State n;

  if( u.size() != 2 ){ cerr << "zly wymiar sterowan\n"; return n; }

  n.Set(s.GetX() + u[0]*dt,s.GetY() + u[1]*dt,0,0,0);

  return n;

}
