#ifndef R_R_T
#define R_R_T

#include <string>
#include <list>
#include <unistd.h>
#include <fstream>
#include "State.hh"
#include "Model.hh"

class RRT{

  list<State> _T;
  double _u;

public:

  RRT();
  void DisplayList();
  void Start();
  void Save();

};


#endif
