#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>

using namespace std;

int main() {
  int N = 2;

  TMatrixD A(N,1);
  TMatrixD B(N,1);
  double Aarray[N] = {1.0, 2.0};
  double Barray[N] = {2.3, 5.4};
  A.SetMatrixArray(Aarray);
  B.SetMatrixArray(Barray);


  TMatrixD C = B.T()*A;
  C.Print();
  double c = TMatrixDRow(C,0)[0];
  cout << c << endl;

  for (int i=5; i>=1; i--) {
    cout << "test" << i << endl;
  };

  return 0;
};
