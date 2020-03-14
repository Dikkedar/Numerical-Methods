#include <TMatrixD.h>
#include <TRandom3.h>
#include <TArrayD.h>
#include <TVectorD.h>

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

TMatrixD RandMatInteger(int MatN, int MatM, int iMax = 10) {
  // Returns a MatN x MatM matrix with random integer < iMax entries
  TRandom3 Rand;
  Rand.SetSeed(0);
  TArrayD MatData(MatN*MatM);
  for (int j=0; j < MatN*MatM; j++) MatData[j] = Rand.Integer(iMax);
  TMatrixD C(MatN,MatM);
  C.SetMatrixArray(MatData.GetArray());
  return C;
};

double VectorProjection(TVectorD A, TVectorD B) {
  // Calculates the projection of vector A onto vector B
  return 0.0;
};
