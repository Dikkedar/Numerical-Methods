#include <iostream>
#include "NewtonRaphson.h"
using namespace std;


// How to define a functor
class MyFunctor {
public:
  double operator() (double x) const {
    double outVal;
    outVal = x*x-1;
    return outVal;
  };
};


int main() {
  // Lambda functions testing grounds

  auto MyLambda = []() {cout << "Testing lambda function." << endl;};
  MyLambda();

  auto LambdaFunc = [](double x) {return x;};
  double C = LambdaFunc(2.0);
  cout << C << endl;


  // std::transform testing ground
  double MyArray1[3] = {2.1, 1.5, 6.3};
  double MyArray2[3] = {9.7, 0.5, 2.3};
  double OutArray[3];

  // How to use a functor
  MyFunctor MyFunction;
  double myd = MyFunction(0.3);
  cout << myd << endl;


  // Example of transform() with binary operation
  // Syntax is transform(inp1Begin, inp1End, inp2Begin, outBegin, binaryOp)
  transform(MyArray1, MyArray1+3, MyArray2, OutArray, plus<double>());
  // Unary syntax is transform(inpBegin, inpEnd, outBegin, unaryOp)


  for (int i = 0; i < 3; i++) cout << OutArray[i] << endl;


  return 0;
};
