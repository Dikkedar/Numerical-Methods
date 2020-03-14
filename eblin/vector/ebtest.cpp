#include <iostream>
#include "ebvector.h"
#include "ebmatrix.h"

// #include <vector>
using namespace std;

int main() {




  // ebvector testing grounds

  int N = 1;
  double x[N] = {6.4, 2.3, 3.1, 4.7};
  double y[N] = {3.4, 2.1, 5.6, 4.3};

  ebvector K(N);

  /*
  ebvector X(N,x);
  X.printVector();
  ebvector Y(N,y);
  X.printVector();
  */


  /*
  // Pointer workstation
  const int N = 4;
  double x[N] = {5.4, 6.8, 4.2, 5.4};
  ebvector* X = new ebvector(N,x);
  X->printVector();
  */



  /*

  ebvector Z(X.size,X.vector);
  Z.printVector();


  */




  const double a = 2;
  //X = a*X;
  //X.printVector();
  //Z.printVector();


  /* ebptrvec pointer testing grounds
  double *M = new double;
  *M = 5.0;
  cout << *M << endl;
  */

  return 0;
}
