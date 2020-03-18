#include <iostream>
// ROOT class for multidim functions
// Only works for dim <= 4...
#include <TFormula.h>
#include <TF1.h>
#include <TMatrixD.h>
using namespace std;

double NewtonRaphson1D(TF1 Func, double Guess) {
  double Tol = 1e-12; // Stops when f(x) is below this
  double ZeroEstimate;
  int steps = 0;

  while (TMath::Abs(Func.Eval(ZeroEstimate)) > Tol) {
    double FuncVal = Func.Eval(ZeroEstimate);
    double FuncDerivVal = Func.Derivative(ZeroEstimate); // Evaluates derivative
    ZeroEstimate += - FuncVal/FuncDerivVal;
    steps += 1;
    // Printf debugging
    //cout << "Function at current value is " << Func.Eval(ZeroEstimate) << endl;
  };
  cout << "Finding root took " << steps << " steps (1D TF1 method)." << endl;
  return ZeroEstimate;
};

double NewtonRaphson1DFinite(TF1 Func, double Guess) {
  double Tol = 1e-12; // Stops when f(x) is below this
  double dx = 1e-6; // For finite difference derivative, must be smaller than delta x
  double ZeroEstimate;
  int steps = 0;

  while (TMath::Abs(Func.Eval(ZeroEstimate)) > Tol) {
    double FuncVal = Func.Eval(ZeroEstimate);
    double FuncDerivVal = (Func.Eval(ZeroEstimate+dx)-Func.Eval(ZeroEstimate))/dx;
    ZeroEstimate += - FuncVal/FuncDerivVal;
    steps += 1;
    // Printf debugging
    //cout << "Function at current value is " << Func.Eval(ZeroEstimate) << endl;
  };
  cout << "Finding root took " << steps << " steps (1D finite method)." << endl;
  return ZeroEstimate;
};

/*
// N-dimensional function that reads from string input like TF classes
class FuncN {
private:
  int Ndim; // Amount of variables
  int Nparams; // Amount of parametres
public:
  FuncN()

  double operator() (double X[Ndim]) {
    return
  };
};
*/

TMatrixD NewtonRaphsonND(TFormula Func, TMatrixD Guess) {
  int dim = Func.GetNdim();
  double Tol = 1e-10; // Stops when f(x) is below this

  double xArray[dim];
  for (int i = 0; i < dim; i++) xArray[i] = TMatrixDRow(Guess,i)[0];

  // while loop until f(x) < tol
  //    calculate jacobian
  //    solve linear system J dx = -f(x)
  //    see if f(xnew=x+dx) < tol, otherwise repeat

  // while (Func.Eval())


  TMatrixD ZeroEstimate(dim,1);
  for (int i = 0; i < dim; i++) TMatrixDRow(ZeroEstimate,i)[0] = xArray[i];
  return ZeroEstimate;
};
