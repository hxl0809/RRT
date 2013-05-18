#ifndef M_O_D_E_L
#define M_O_D_E_L

#include "State.hh"
#include <vector>

class Model{


public:

  Model();
  static vector<double> SelectInput( State s1, State s2 );
  static State NewState( State s, vector<double> u, double dt );


};


#endif
