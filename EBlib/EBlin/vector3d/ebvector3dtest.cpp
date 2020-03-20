#include <iostream>
#include "ebvector3d.h"
using namespace std;

int main() {
  ebvector3d X(2.1,3.2,4.3);
  const double a = 3.4;
  ebvector3d Y = a*X;
  ebvector3d Z = Y+X;
  X.printVector();
  Y.printVector();
  Z.printVector();

  return 0;
}
