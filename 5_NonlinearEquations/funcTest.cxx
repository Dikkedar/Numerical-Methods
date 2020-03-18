#include <iostream>
#include "EBFunction.h"
using namespace std;

int main() {
  string MyFuncString = "2*x-3";
  EBFunction MyFunc(MyFuncString);




  vector<double> inp{0.25}; // Later make this so it can take doubles also 
  double MyNumber = MyFunc(inp);



  return 0;
};
