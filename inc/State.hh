#ifndef S_T_A_T_E
#define S_T_A_T_E

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <list>
#include <cmath>

#define INF 100000000

using namespace std;

class State{

  double _x;
  double _y;
  double _theta;
  double _delta;
  double _phi;

public:

  State();
  State( double x, double y, double theta, double delta, double phi );
  //State( const State& s );
  State Set( double x, double y, double theta, double delta, double phi );
  void Display();
  static State RandomState();
  double Delta( State s );
  State NearestNeighbor( list< State > l );
  double GetX();
  double GetY();
  double GetTheta();
  double GetDelta();
  double GetPhi();

};


#endif
