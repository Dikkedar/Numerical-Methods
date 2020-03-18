#include <iostream>
#include "EBParser.h"
using namespace std;

int main() {
  string TestInfix = "2*3+4/(6-7)";
  EBParser TestParse(TestInfix);

  return 0;
}
