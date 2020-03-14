/*
   FINDS (ALL) EIGENVALUES AND EIGENVECTORS OF A GIVEN MATRIX WITH THE
   JACOBI EIGENVALUE ALGORITHM
   http://62.107.14.89/~fedorov/old/prog-2019/numeric/book/eigen.pdf
   USES ROOT FOR VECTORS AND MATRICES
*/

#include <string>
#include <cmath>
#include <iostream>
#include <TMatrixD.h>
#include <TMatrixDEigen.h>
#include <TArrayD.h>
#include <TRandom3.h>
#include <TMath.h>
using namespace std;

//______________________________________________________________________________

TMatrixD RandMat(int MatN, int MatM) {
  // Returns a MatN x MatM matrix with random entries
  TRandom3 Rand; Rand.SetSeed(0);
  TArrayD MatData1(MatN*MatM); // Initialize TArrayD class
  for (int j=0; j < MatN*MatM; j++) MatData1[j] = Rand.Rndm(); // Fill array
  TMatrixD C(MatN,MatM);
  C.SetMatrixArray(MatData1.GetArray());
  return C;
};

TMatrixD RandMatSym(int MatN) {
  // Returns a MatN x MatN matrix with symmetric, random entries
  // Not the most elegant way, I know...
  TMatrixD C(MatN,MatN);
  C = RandMat(MatN,MatN);
  for (int i = 0; i < MatN; i++) {
    for (int j = 0; j < i; j++) {
      TMatrixDRow(C,i)[j] = TMatrixDRow(C,j)[i];
    };
  };
  return C;
};

TMatrixD JacRotMat(TMatrixD inpMat, int p, int q) {
  // Creates the Jacobi rotation matrix to reduce element (p,q)
  int N = inpMat.GetNrows();
  int M = inpMat.GetNcols();
  TMatrixD JacMat(N,M);
  JacMat.UnitMatrix(); // Start with unit matrix
  double inpPQ = TMatrixDRow(inpMat,p)[q]; // Get elements to change in inpMat
  double inpQQ = TMatrixDRow(inpMat,q)[q];
  double inpPP = TMatrixDRow(inpMat,p)[p];
  Double_t phi;

  // Create the Jacobi rotation matrix from equations in the pdf
  if (inpQQ == inpPP) phi = TMath::Pi()/4; // Avoid division by zero
  else phi = TMath::ATan(2*inpPQ/(inpQQ-inpPP))/2;
  TMatrixDRow(JacMat,p)[p] = TMath::Cos(phi);
  TMatrixDRow(JacMat,q)[q] = TMath::Cos(phi);
  TMatrixDRow(JacMat,p)[q] = TMath::Sin(phi);
  TMatrixDRow(JacMat,q)[p] = -TMath::Sin(phi);

  return JacMat;
};

TMatrixD JacRotate(TMatrixD inpMat, int p, int q) {
  // Outputs the (p,q) Jacobi-rotated input matrix
  int N = inpMat.GetNrows();
  int M = inpMat.GetNcols();

  TMatrixD JacMat(N,M); // Get Jacobi rotation matrix
  JacMat = JacRotMat(inpMat, p, q);

  TMatrixD NewMat(N,M); // Carry out matrix multiplication
  NewMat = inpMat*JacMat;
  NewMat = JacMat.T()*NewMat;
  return NewMat;
};

TMatrixD JacSweep(TMatrixD inpMat) {
  // Carries out a sweep, i.e. JacRotates all off-diagonal elements
  int N = inpMat.GetNrows();
  int M = inpMat.GetNcols();
  TMatrixD outMat(N,M);
  outMat = inpMat;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (j != i) { // Do not rotate diagonal entries
        outMat = JacRotate(outMat, i, j);
      };
    };
  };
  return outMat;
};

Double_t OffDiagNorm(TMatrixD inpMat) {
  // Returns the norm-square of off-diagonal elements
  // Sets diagonal to zero and uses the TMatrixD method E2Norm()
  int N = inpMat.GetNrows();
  int M = inpMat.GetNcols();
  for (int j = 0; j < N; j++) {
    TMatrixDRow(inpMat,j)[j] = 0;
  };
  return inpMat.E2Norm();
};

TMatrixD JacDiagCyclic(TMatrixD inpMat, double Tolerance) {
  /*
    The Jacobi diagonalization functions, cyclic method
    Returns the diagonalized matrix
    Possible extensions:
      - Output amount of steps taken
      - Also yield eigenvectors
  */
  int N = inpMat.GetNrows();
  int M = inpMat.GetNcols();
  TMatrixD outMat(N,M);
  outMat = inpMat;
  double OffDiagRes;
  OffDiagRes = OffDiagNorm(inpMat);

  while (OffDiagRes > Tolerance) {
    outMat = JacSweep(outMat);
    OffDiagRes = OffDiagNorm(outMat);
  };

  // Optional: Kills all off-diagonal elements to output clean matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (j != i) { // Do not rotate diagonal entries
        TMatrixDRow(outMat,i)[j] = 0;
      };
    };
  };
  return outMat;
};
