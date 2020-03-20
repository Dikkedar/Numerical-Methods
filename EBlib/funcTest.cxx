#include <iostream>
#include "EBFunction.h"
using namespace std;

int main() {
  string MyFuncString = "2*x-3/(7-6*x)";
  EBFunction MyFunc(MyFuncString);




  // Later make this so it can take doubles also
  // Do this by learning about function templates
  vector<double> inp{0.25};
  double MyNumber = MyFunc(inp);



  return 0;
};
