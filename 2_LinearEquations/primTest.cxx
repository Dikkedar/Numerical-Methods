#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "MatrixUtilities.h"

using namespace std;

int main() {
  int N = 2;

  TMatrixD A(N,1);
  TMatrixD B(N,1);
  double Aarray[N] = {658.0, 0.35};
  double Barray[N] = {0.0, 1.0};
  A.SetMatrixArray(Aarray);
  B.SetMatrixArray(Barray);

  TMatrixD ProjTest(N,1);
  ProjTest = VectorProjectionMatrix(A,B);
  ProjTest.Print();

  /*
  TMatrixD C(N,N);
  C = RandMatInteger(N,N,10);
  TMatrixD CTransp(N,N);
  CTransp = Transpose(C);
  C.Print();
  CTransp.Print();

  TMatrixD C = B.T()*A;
  C.Print();
  double c = TMatrixDRow(C,0)[0];
  cout << c << endl;

  for (int i=5; i>=1; i--) {
    cout << "test" << i << endl;
  };
  */
  return 0;
};
