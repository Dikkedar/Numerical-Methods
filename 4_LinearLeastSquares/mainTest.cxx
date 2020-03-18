#include <iostream>
#include "LeastSquares.h"
// #include "../2_LinearEquations/QRDecomposition.h"
// ../MatrixUtilities.h is imported through QRDecomposition.h
using namespace std;

int main() {
  cout << "************************" << endl;
  cout << "Linear least squares problem " << endl;
  cout << "  Find best c such that Ac=b => find x = min(Ac-b)"<< endl;
  cout << "************************" << endl;

  int N = 4;
  int M = N; // Only works with square matrices so far

  // Generate random matrix and vector
  TMatrixD TestMat(N,M);
  TestMat = RandMatInteger(N,M);
  cout << "A matrix is";
  TestMat.Print();

  TMatrixD TestVec(N,1);
  TestVec = RandMatInteger(N,1,10);
  cout << "b vector is";
  TestVec.Print();






  return 0;
};
