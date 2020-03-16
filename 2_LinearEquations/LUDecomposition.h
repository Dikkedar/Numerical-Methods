#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "MatrixUtilities.h"
using namespace std;

class LUDecomposition {
public:
  TMatrixD AMat;
  TMatrixD LMat; // Lower (left) triangular matrix
  TMatrixD UMat; // Upper (right) triangular matrix 
  int N;
  int M;

  LUDecomposition (TMatrixD A) {
    int N = A.GetNrows();
    int M = A.GetNcols();
    AMat.ResizeTo(N,M);
    AMat = A;

  };

};
