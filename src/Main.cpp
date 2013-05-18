#include "RRT.hh"

using namespace std;

int main(int argc, char** argv){

  srand(time(NULL));

  extern char* optarg;

  string input;
  string output;

  char c;

  while ((c = getopt(argc, argv, "i:o:")) != -1){

    switch (c){
    case 'i': input += optarg;
      break;
    case 'o': output += optarg;
      break;

    }

  }

  RRT r;
  //r.DisplayList();
  r.Start();
  //r.SavePath();
  //r.SavePoints();

}
