#include <iostream>
#include <typeinfo>
#include <vector>
#include <stack>  // I'm trying out some STL containers here, as you can see...
#include <queue>
#include <map>
using namespace std;



class EBParser {
  /*
  Perhaps a little too explicit, but was a fun challenge...
  This class contains the rules of my arithmetic language!

  The general language is on the form
  "x*3+2/(7-3)" for 1-variable functions
  "x[0]*3+2*x[1]/(7-3)" for multivariable functions
  "x[0]*C[0]+7/(C[1]-3)" for variables and parameters

  Spaces are also allowed:
  "x * 3 + 2 / (7 - 3)" is equivalent to "x*3+2/(7-3)"
  */

public:
  string InfixExpr;
  string RPNExpr;

  // Map (i.e. dictionary) containing operator precedences, keys are chars, values are ints
  // This allows easy addition of new operators and things
  const char OperatorList[] = "+-*/^";
  map<char, int> OperatorPrecedence;
  OperatorPrecedence['+'] = 0;
  OperatorPrecedence['-'] = 1;
  OperatorPrecedence['*'] = 2;
  OperatorPrecedence['/'] = 3;
  OperatorPrecedence['^'] = 4;

  EBParser(string inpExpr = "") {
    InfixExpr = inpExpr; // Input expression is in infix
  };

  string TokenType(char Token);
  void Infix2RPN(string inpExpr);
};





string EBParser::TokenType(char Token) {
  string Type;

  // Determine the type of the input token
  for (char OperatorSymbol: OperatorList) {
    cout << typeid(OperatorSymbol).name() << ", " << typeid(Token).name() << endl;
    if (Token == OperatorSymbol) Type = "Operator";
  };
  if (Token == '(' || Token == ')') Type = "Bracket";
  else if (Token == 'x') Type = "Variable";
  else if (Token == 'C') Type = "Parameter";
  else Type = "Number";

  return Type;
};







void EBParser::Infix2RPN(string inpExpr) {
  /*
    Conversion from infix to Reverse Polish notation, Shunting Yard algorithm
    A good resource is https://www.youtube.com/watch?v=QzVVjboyb0s
  */
  
  stack<double> OperatorStack;
  queue<char> OutputQueue;

  int exprLength = InfixExpr.length();
  for (int i = 0; i < exprLength; i++) { // Loop over tokens in func definition
    char Token = InfixExpr[i];

    // Determine type of token
    string TType = TokenType(Token);

    cout << "Token is " << Token << ", type is " << TType << endl;


    if (TType == "Number") OutputQueue.push(Token);

  };

  string RPNConvert;
  RPNExpr = RPNConvert;
};
