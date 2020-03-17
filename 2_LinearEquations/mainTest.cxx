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
  TestMat = RandMatIntegerPos(N,M);

  QRDecomposition QRTest(TestMat);
  cout << "\n************************" << endl;
  cout << "QR Decomposition by Gram Schmidt Orthogonalization Test" << endl;
  cout << "\n************************" << endl;
  cout << "\nAMat";
  QRTest.AMat.Print();

  QRTest.GramSchmidt();

  cout << "\nAFTER DECOMPOSITION, QMat";
  QRTest.QMat.Print();

  TMatrixD TestMat2(N,N);
  TMatrixD QTransp = Transpose(QRTest.QMat);
  TestMat2 = QTransp*QRTest.QMat; // Should equal unity, check

  cout << "\nAFTER DECOMPOSITION, RMat";
  QRTest.RMat.Print(); // Should be upper (right) triangular

  cout << "\nDecomposition finalized." << endl;

  // Generate random c-vector for system A*x=c
  TMatrixD bvec(N,1);
  bvec = RandMatInteger(N,1,10);
  cout << "The coefficient vector b is" << endl;
  bvec.Print();

  // By QR decomposition, Ax=b => Rx = Q^T*b
  TMatrixD cvec(N,1);
  cvec = QRTest.QTransp*bvec;

  // Solve the system of equations Amat*x = bvec
  TMatrixD eqSolution(N,1) = BackSubstitution(cvec, QRTest.RMat);
  cout << "\nTHE SOLUTION TO AMat*x=b IS";
  eqSolution.Print();

  return 0;
};
