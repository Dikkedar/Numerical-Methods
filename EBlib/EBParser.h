#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm> // std::count
#include <stack>  // I'm trying out some STL containers here, as you can see...
#include <queue>
#include <list>
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

  Extensions to do:
    - Accept doubles instead of only ints
    - Accept x[n] and C[n] as multidimensional variables and parameters
    - Allow white spaces in expressions
    - Work on making parser accept 6x as 6*x


  */

public:
  string InfixExpr;
  string RPNExpr;

  // Map (i.e. dictionary) containing operator precedences, keys are chars, values are ints
  // This allows easy addition of new operators and things
  const vector<char> OperatorList{'+','-','*','/','^'};
  map<char, int> OperatorPrecedence;


  void SetGrammar();
  string TokenType(char Token);
  void Infix2RPN();
  double EvaluateRPN(string inpExpr);


  EBParser(string inpExpr = "") {
    InfixExpr = inpExpr; // Input expression is in infix
    SetGrammar();
  };
};

void EBParser::SetGrammar() {
  OperatorPrecedence['+'] = 0;
  OperatorPrecedence['-'] = 1;
  OperatorPrecedence['*'] = 2;
  OperatorPrecedence['/'] = 3;
  OperatorPrecedence['^'] = 4;
};

string EBParser::TokenType(char Token) {
  string Type;

  // Determine the type of the input token
  if (count(OperatorList.begin(), OperatorList.end(), Token) != 0) Type = "Operator";
  else if (Token == '(') Type = "LeftBracket";
  else if (Token == ')') Type = "RightBracket";
  else if (Token == 'x') Type = "Variable"; // And if >1 var, skip next 3 chars in tokenlist
  else if (Token == 'C') Type = "Parameter"; // And if >1 par, skip next 3 chars in tokenlist
  else Type = "Number";

  // Testing
  //cout << "Token is " << Token << ", type is " << TType << endl;
  return Type;
};



void EBParser::Infix2RPN() {
  /*
    Conversion from infix to Reverse Polish notation, Shunting Yard algorithm
    A good resource is https://www.youtube.com/watch?v=QzVVjboyb0s
  */
  string inpExpr = InfixExpr;

  stack<char> OperatorStack;
  queue<char> OutputQueue;

  int exprLength = InfixExpr.length();
  for (int i = 0; i < exprLength; i++) { // Loop over tokens in func definition
    char Token = InfixExpr[i];

    // Determine type of token
    string TType = TokenType(Token);
    if (TType == "Number") OutputQueue.push(Token);
    else if (TType == "Operator") {
      // Push operator through all operators in stack with lower precedence
      while (not OperatorStack.empty() && OperatorPrecedence[OperatorStack.top()] > OperatorPrecedence[Token]) {
        OutputQueue.push(OperatorStack.top()); // Pop from OperatorStack to OutputQueue
        OperatorStack.pop();
      };
      OperatorStack.push(Token); // Push current operator to stack
    }
    else if (TType == "LeftBracket") OperatorStack.push(Token);
    else if (TType == "RightBracket") {
      while (OperatorStack.top() != '(') {
        OutputQueue.push(OperatorStack.top()); // Pop from OperatorStack to OutputQueue
        OperatorStack.pop();
      };
      OperatorStack.pop(); // Pop the left bracket; if there is none, you have mismatched brackets!
    };
  };
  while (not OperatorStack.empty()) { // Pop the rest of the operators to the queue
    OutputQueue.push(OperatorStack.top());
    OperatorStack.pop();
  };

  // RPN expression now sits in the OutputQueue
  string RPNConvert;
  while (not OutputQueue.empty()) {
    char NewChar = OutputQueue.front();
    RPNConvert.push_back(NewChar);
    OutputQueue.pop();
  };
  RPNExpr = RPNConvert; // Set class variable
};


double EBParser::EvaluateRPN(string inpRPN) {
  stack<char> OperatorStack;
  stack<int> OperandStack;
  int ExpressionLength = inpRPN.length();
  for (int j = 0; j < ExpressionLength; j++) { // Loop over tokens
    char Token = inpRPN[j];
    string TType = TokenType(inpRPN[j]);
    if (TType == "Operator") OperatorStack.push(Token);
    else if (TType == "Number") { // These should be the only possibilities
      if (not OperandStack.empty()) {
        // Convert char operands to number and do operation
        int Operand1 = OperandStack.top()-'0';
        OperandStack.pop();
        int Operand2 = Token - '0';
        char CurrentOperator = OperatorStack.top();
        OperatorStack.pop();

        int NewOperand;
        if (CurrentOperator == '*') { // Carry out operation

        };
      };
    };
  };



  double val = 0;






  return val;
};
