#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

class complex {
public:
  double Re;
  double Im;

  complex (double a=0.0, double b=0.0) {
    Re = a;
    Im = b;
  };

  void print() { // Prints the complex number properly
    if (Im >= 0) {
      cout << Re << " + " << Im << "i" << endl;
    } else {
      cout << Re << " - " << -Im << "i" << endl;
    }};
};


// Addition of two complex numbers
complex operator+(complex z1, complex z2) {
  double newRe = z1.Re + z2.Re;
  double newIm = z1.Im + z2.Im;
  complex z(newRe, newIm);
  return z;
};

// Subtraction of two complex numbers
complex operator-(complex z1, complex z2) {
  double newRe = z1.Re - z2.Re;
  double newIm = z1.Im - z2.Im;
  complex z(newRe, newIm);
  return z;
};

// Multiplication of two complex numbers
complex operator*(complex z1, complex z2) {
  double newRe = z1.Re*z2.Re - z1.Im*z2.Im;
  double newIm = z1.Re*z2.Im + z1.Im*z2.Re;
  complex z(newRe, newIm);
  return z;
};

// Complex exponential function
complex cexp(double t) {
  double newRe = cos(t);
  double newIm = sin(t);
  complex z(newRe, newIm);
  return z;
};

// Complex conjugate
complex conj(complex z) {
  complex w(z.Re, -z.Im);
  return w;
};

// Inverse of complex number
complex cinv(complex z) {
  double x = z.Re;
  double y = z.Im;
  double r = x*x + y*y;
  assert(r != 0); // Check for division by zero error
  complex w(x/r, -y/r);
  return w;
};

/*
    POLAR FORM OF A COMPLEX NUMBER
*/

class complexPolar {
public:
  double modulus;
  double argument;

  complexPolar (double a=1.0, double b=0.0) {
    modulus = a;
    argument = b;
  };
};
