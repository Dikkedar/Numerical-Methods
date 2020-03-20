#include <iostream>
#include "EBParser.h"
using namespace std;

int main() {
  string TestInfix = "2*3+4/(6-7)";
  EBParser TestParse(TestInfix);

  TestParse.Infix2RPN();

  char myChar = '0' + 2;
  cout << myChar << endl;
  char TestChar = '2';
  int TestInt = TestChar-'0';
  cout << "Char:" << TestChar << ", Int: "<< TestInt << endl;


  cout << "Infix expression: " << TestParse.InfixExpr << endl;
  cout << "RPN expression: " << TestParse.RPNExpr << endl;

  double RPNeval = 0.0;

  cout << "RPN evaluation: " << RPNeval << endl;

  return 0;
}
