#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

int main() {
  complex z(1.0,-2.0);
  complex w(0.0,1.0);
  complex p = z+w; // addition of complex numbers (also works with -)
  complex q = z*w; // multiplication
  complex qcon = conj(q); // complex conjugation
  complex u = cexp(M_PI);  // complex exponential
  complex k = cinv(z); // inverse of complex number
  complex zh = k*z;
  zh.print(); // Why is this not =z?
  return 0;
}
