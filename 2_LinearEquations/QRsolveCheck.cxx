#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "QRDecomposition.h"

using namespace std;

int main() {
  int N = 4;
  int M = 4;

  // Generate random matrix, integer entries
  TMatrixD TestMat(N,M);
  TestMat = RandMatInteger(N,M);
  cout << "Amat is";
  TestMat.Print();

  // Generate random c-vector for system A*x=c
  TMatrixD bvec(N,1);
  bvec = RandMatInteger(N,1,10);
  cout << "\nThe coefficient vector b is";
  bvec.Print();

  TMatrixD Sol(N,1);
  Sol = QRSolveGramSchmidt(TestMat, bvec);

  cout << "\nThe solution is";
  Sol.Print();

  cout << "Amat*Sol =";
  TMatrixD Test(N,1);
  Test = TestMat*Sol;
  Test.Print();



  return 0;
};
