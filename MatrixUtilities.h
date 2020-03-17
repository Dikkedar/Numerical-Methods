#include <iostream>
#include <TMatrixD.h>
#include <TRandom3.h>
#include <TArrayD.h>
#include <TVectorD.h>
using namespace std;

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

TMatrixD RandMatIntegerPos(int MatN, int MatM, int iMax = 10) {
  // Returns a MatN x MatM matrix with random integer < iMax entries, positive
  TRandom3 Rand;
  Rand.SetSeed(0);
  TArrayD MatData(MatN*MatM);
  for (int j=0; j < MatN*MatM; j++) MatData[j] = Rand.Integer(iMax);
  TMatrixD C(MatN,MatM);
  C.SetMatrixArray(MatData.GetArray());
  return C;
};

TMatrixD RandMatInteger(int MatN, int MatM, int iMax = 10) {
  // Returns a MatN x MatM matrix with random integer -iMax < n < iMax
  TRandom3 Rand;
  Rand.SetSeed(0);
  TArrayD MatData(MatN*MatM);
  float avg = iMax;
  for (int j=0; j < MatN*MatM; j++) MatData[j] = Rand.Integer(iMax+iMax)-avg;
  TMatrixD C(MatN,MatM);
  C.SetMatrixArray(MatData.GetArray());
  return C;
};

TMatrixD Transpose(TMatrixD A) {
  // Returns matrix transpose of a square matrix
  int N = A.GetNrows();
  TMatrixD ATransp(N,N);
  for (int i = 0; i < N; i++) { // Loop over rows
    for (int j = 0; j < N; j++) { // Loop over columns
      if (i != j) {
        TMatrixDRow(ATransp,i)[j] = TMatrixDRow(A,j)[i];
        TMatrixDRow(ATransp,j)[i] = TMatrixDRow(A,i)[j];
      }
      else { // Diagonal
        TMatrixDRow(ATransp,i)[j] = TMatrixDRow(A,i)[j];
      }
    };
  };
  return ATransp;
};

// Defining dot product of vectors, can't see if this already exists...
double VectorDot(TVectorD A, TVectorD B) {
  // Assuming A and B have the same length
  double k = 0.0;
  int N = A.GetNoElements();
  for (int j = 0; j < N; j++) k += A[j]*B[j];
  return k;
};

// Defining dot product of vectors, can't see if this already exists...
double VectorDotMatrix(TMatrixD A, TMatrixD B) {
  // Assuming A and B have the same length, Nx1 matrices
  double k = 0.0;
  int N = A.GetNrows();
  for (int j = 0; j < N; j++) {
    double Arow = TMatrixDRow(A,j)[0];
    double Brow = TMatrixDRow(B,j)[0];
    k += Arow*Brow;
  };
  return k;
};

TVectorD VectorProjection(TVectorD A, TVectorD B) {
  // Calculates the projection of vector A onto vector B
  int N = A.GetNoElements();
  TVectorD ProjectedVector(N);
  double Coefficient = VectorDot(A,B)/VectorDot(B,B);
  ProjectedVector = Coefficient*B;
  return ProjectedVector;
};

TMatrixD VectorProjectionMatrix(TMatrixD A, TMatrixD B) {
  // Calculates the projection of A onto B, both are Nx1 matrices
  int N = A.GetNrows();
  TMatrixD ProjectedVector(N,1);
  TMatrixD temp1 = A.T()*B;
  double coef1 = TMatrixDRow(temp1,0)[0];
  double coef2 = 0.0;
  for (int i = 0; i < N; i++) coef2 += TMatrixDRow(B,i)[0]*TMatrixDRow(B,i)[0];
  double Coefficient = coef1/coef2;
  ProjectedVector = Coefficient*B;

  return ProjectedVector;
};
