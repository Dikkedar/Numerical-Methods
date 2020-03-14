#include <iostream>
#include <TMatrixD.h>

using namespace std;

// Prototyping
TMatrixD ERO1(TMatrixD M, int i, int j);
TMatrixD ERO2(TMatrixD M, int i, double s);
TMatrixD ERO3(TMatrixD M, int i, int j, double s);
TMatrixD GaussElim(TMatrixD M);

int main() {
  TMatrixD Mat(3,3);
  double MatData[9] = {1,2,3,4,5,6,7,8,9};
  Mat.SetMatrixArray(MatData);

  cout << "INITIAL MATRIX";
  Mat.Print();

  // ERO 1
  TMatrixD Mat2(3,3);
  Mat2 = ERO1(Mat, 0, 1);
  cout << "\nAFTER ERO1";
  Mat2.Print();

  // ERO 2
  TMatrixD Mat3(3,3);
  Mat3 = ERO2(Mat2, 1, 0.5);
  cout << "\nAFTER ERO2";
  Mat3.Print();

  // ERO 3
  TMatrixD Mat4(3,3);
  Mat4 = ERO3(Mat3, 1, 2, 0.1);
  cout << "\nAFTER ERO3";
  Mat4.Print();

  // Full Gauss elimination
  TMatrixD Mat5(3,3);
  Mat5 = GaussElim(Mat);
  cout << "\nAFTER GAUSS ELIMINATION";
  Mat5.Print();


  return 0;
};


/*
    GAUSSIAN ELIMINATION UTILITIES

*/

// Elementary row operation 1: Interchange rows i and j
TMatrixD ERO1(TMatrixD M, int i, int j) {
  TMatrixD outM = M;
  TMatrixDRow tempRow = TMatrixDRow(outM,i);
  TMatrixDRow(outM,i) = TMatrixDRow(outM,j);
  TMatrixDRow(outM,j) = tempRow; // This does not seem to work!
  return outM;
};

// Elementary row operation 2: Multiply i by s, s != 0
TMatrixD ERO2(TMatrixD M, int i, double s) {
  TMatrixD outM = M;
  TMatrixDRow(outM,i) *= s;
  return outM;
};

// Elementary row operation 3: Add row i times s to row j
TMatrixD ERO3(TMatrixD M, int i, int j, double s) {
  TMatrixD outM = M;
  TMatrixDRow addRow = TMatrixDRow(M,i);
  addRow *= s;
  TMatrixDRow jRow = TMatrixDRow(M,j);
  jRow += addRow; // How to add two rows?
  TMatrixDRow(outM,j) = jRow;
  return outM;
};

// Carry out Gauss Elimination algorithm on input matrix
TMatrixD GaussElim(TMatrixD M) {
  TMatrixD outM(3,3);
  outM = M;
  return outM;
}
