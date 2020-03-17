#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "QRDecomposition.h"

using namespace std;

int main() {
  int N = 4; // Try N=100 to see speed
  int M = N; // Only works with square matrices so far

  // Generate random matrix, integer entries
  TMatrixD TestMat(N,M);
  TestMat = RandMatInteger(N,M);

  QRDecomposition QRTest(TestMat);
  cout << "\n************************" << endl;
  cout << "QR Decomposition by Gram Schmidt Orthogonalization Test" << endl;
  cout << "     A = QR, Q orthogonal, R upper triangular\n************************" << endl;
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

  double ADet = QRTest.Determinant();
  cout << "\nAbs(Determinant of A) is " << ADet << "." << endl;

  TMatrixD AInv(N,N);
  AInv = QRTest.AInverse();
  cout << "\nThe inverse of A is ";
  AInv.Print();

  TMatrixD InvCheck(N,N);
  InvCheck = AInv*QRTest.AMat;
  cout << "\nAInv*A unity check:";
  InvCheck.Print();

  cout << "\nLinear equations solving test." << endl;
  // Generate random c-vector for system A*x=c
  TMatrixD bvec(N,1);
  bvec = RandMatInteger(N,1,10);
  cout << "The coefficient vector b is";
  bvec.Print();

  // By QR decomposition, Ax=b => Rx = Q^T*b
  TMatrixD cvec(N,1);
  cvec = QRTest.QTransp*bvec;

  // Solve the system of equations Amat*x = bvec
  TMatrixD eqSolution(N,1);
  eqSolution = BackSubstitution(cvec, QRTest.RMat);
  cout << "\nTHE SOLUTION TO AMat*x=b IS";
  eqSolution.Print();

  cout << "\nSOLUTION CHECK: AMat*eqSolution=";
  TMatrixD newVec(N,1);
  newVec = QRTest.AMat*eqSolution;
  newVec.Print();

  return 0;
};
