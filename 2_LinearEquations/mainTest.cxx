#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "QRGramSchmidt.h"
#include "MatrixUtilities.h"

using namespace std;

int main() {
  int N = 4;
  int M = 4;

  // Generate random matrix, integer entries
  TMatrixD TestMat(N,M);
  TestMat = RandMatInteger(N,M,10);

  QRDecomposition QRTest(TestMat);
  QRTest.AMat.Print();

  TVectorD Vec1[2];
  TVectorD Vec2[2];
  Vec1[0] = 2.0;
  Vec1[1] = 3.2;
  Vec2[0] = 5.4;
  Vec2[1] = 6.7;

  double K;
  K = Vec1.Dot(Vec2);
  cout << K << endl;


  cout << "\nTest finalized." << endl;
  return 0;
};
