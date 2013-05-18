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

  list< State* > _successors;
  State* _parent;

public:

  State();
  State( double x, double y, double theta, double delta, double phi, State* parent = NULL );
  //State( const State& s );
  ~State();
  State Set( double x, double y, double theta, double delta, double phi );
  State Display();
  static State RandomState();
  double Delta( State s );
  State* NearestNeighbor( list< State* > l );
  double GetX();
  double GetY();
  double GetTheta();
  double GetDelta();
  double GetPhi();
  list<State*> GetSuccessors();
  State* GetParent();
  State AddSuccessor( State *s );
  State SetParent( State *s );

};


#endif
