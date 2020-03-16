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

  QRDecomposition QRTest(TestMat);
  QRTest.AMat.Print();

  QRTest.GramSchmidt();

  cout << "\nAFTER DECOMPOSITION, QMat";
  QRTest.QMat.Print();
  cout << "\nAFTER DECOMPOSITION, RMat";
  QRTest.RMat.Print();

  cout <<"\nSHOULD EQUAL UNITY";
  TMatrixD TestMat2(N,N);
  TestMat2 = QRTest.QMat.T()*QRTest.QMat;
  TestMat2.Print(); // Should equal unity

  cout << "\nTest finalized." << endl;

  // Generate random c-vector for system A*x=c
  TMatrixD bvec(N,1);
  bvec = RandMatInteger(N,1,10);

  // By QR decomposition, Ax=b => Rx = Q^T*b
  TMatrixD cvec(N,1);
  cvec = QRTest.QMat.T()*bvec;

  // Solve the system of equations Amat*x = bvec
  TMatrixD eqSolution(N,1);
  eqSolution = BackSubstitution(cvec, QRTest.RMat);
  cout << "\nTHE SOLUTION IS";
  eqSolution.Print();

  return 0;
};
