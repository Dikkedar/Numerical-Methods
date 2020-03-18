#include <iostream>
#include <vector>
#include "EBParser.h"
#include "../StringUtilities.h"
using namespace std;

class EBFunction {
public:
  int Ndim; // Amount of variables
  int Nparams; // Amount of parametres
  string FunctionDefinition;
  string FunctionRPN;
  EBParser ExprParser;

  int FindFunctionDim(string FuncDef);
  int FindFunctionParamDim(string FuncDef);
  double EvaluateFunction(vector<double> X);

  EBFunction(string FunctionDef) { // Function definition should be in infix notation
    Ndim = FindFunctionDim(FunctionDefinition);
    Nparams = FindFunctionParamDim(FunctionDefinition);
    FunctionDefinition = FunctionDef; // Save definition if supplied
    ExprParser.InfixExpr = FunctionDef; // Load definition into parser
  };


  // Use this to evaluate function as functor
  double operator() (vector<double> X) {return EvaluateFunction(X);};
};



double EBFunction::EvaluateFunction(vector<double> X) {
  // Evaluates the function at the given coordinate
  // Using EvaluateRPN, we only need to insert variables in the expr string
  double value;
  return value;
};






/*
    OTHER UTILITY FUNCTIONS

*/

int EBFunction::FindFunctionDim(string FunctionDefinition) {
  // Finds the amount of variables in a function
  // Variables must be declared as x[0], x[1], ...
  vector<int> VarVec;
  // This should suffice as long as you don't use "x" other than for variables
  VarVec = FindLetters(FunctionDefinition, "x");
  return VarVec.size();
};

int EBFunction::FindFunctionParamDim(string FunctionDefinition) {
  // Finds amount of parametres in a function
  // Parameters must be declared as C[0], C[1], ...
  vector<int> ParVec;
  // This should suffice as long as you don't use "C" other than for parametres
  ParVec = FindLetters(FunctionDefinition, "C");
  return ParVec.size();
};
