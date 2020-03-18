#include <iostream>
#include "NewtonRaphson.h"
using namespace std;

int main() {
  /*
      1D TESTING

  */


  double Param1 = 0.3;
  double ZeroGuess = 0.6;

  // Easy test with a simple function
  TF1 TestFunc1("","(x-[0])^2+x^3 - 21.2 + x^5");
  TestFunc1.SetParameter(0, Param1);
  double MyZero;
  MyZero = NewtonRaphson1D(TestFunc1, ZeroGuess);
  cout << "TF1 Method: I found: " << MyZero << endl << endl;

  double MyZero2;
  MyZero2 = NewtonRaphson1DFinite(TestFunc1, ZeroGuess);
  cout << "Finite method: I found: " << MyZero2 << endl;




  /*
    MULTIDIMENSIONAL TESTING

  */

  // ROOT class for multidimensional functions
  int Dim = 4;
  TFormula TestFunc("","x[0]+x[1]+x[2]+x[3]");
  double MyGuess[Dim] = {0.2,0.3,0.5,0.2};
  TMatrixD GuessMat(Dim,1);
  GuessMat.SetMatrixArray(MyGuess);
  double val1 = TestFunc.Eval(MyGuess[0],MyGuess[1],MyGuess[2],MyGuess[3]);

  /*
  TMatrixD MyZero(4,1);
  MyZero = NewtonRaphsonND(TestFunc,GuessMat);
  MyZero.Print();
  */
  return 0;
};
