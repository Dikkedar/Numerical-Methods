#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "QRGramSchmidt.h"

using namespace std;

int main() {
  int N = 4;
  int M = 4;

  // Generate random matrix, integer entries
  TMatrixD TestMat(N,M);
  TestMat = RandMatInteger(N,M,10);

  QRDecomposition QRTest(TestMat);
  QRTest.AMat.Print();

  QRTest.GramSchmidt();

  cout << "\nAFTER DECOMPOSITION, QMat";
  QRTest.QMat.Print();
  cout << "\nAFTER DECOMPOSITION, RMat";
  QRTest.RMat.Print();

  cout << "\nTest finalized." << endl;


  return 0;
};
