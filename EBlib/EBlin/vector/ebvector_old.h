/*
  My own N-vector class

*/
#include <iostream>
#include <assert.h>
#include <array>
using namespace std;

class ebvector {
  // Takes a list as input and makes a vector with appropriate operations possible
public:
  int size; // initialization moved to constructor
  double vector[]; //

  // Constructor
  ebvector(int N, double vec[]) {
    /*const int size(N);
    double vector[N];*/
    size = N;

    // Copy array into the class vector
    for (int j=0; j < size; j++) {
      vector[j] = vec[j];
    };
  };

  void printVector() {
    // Function to print every element in vector
    for (int j=0; j < size; j++) {
      cout << vector[j] << " ";
    };
    cout << endl;
  };
};

// Vector multiplication by a scalar
ebvector operator*(const double a, ebvector X){
  ebvector Y(X.size, X.vector);
  for (int j=0; j<X.size; j++) {
    cout << j << a*Y.vector[j] << endl;
    Y.vector[j] = a*Y.vector[j];
  };
  return Y;
};

// Vector addition
ebvector operator+(ebvector X, ebvector Y){
  assert(X.size == Y.size); // check that the sizes are equal before adding
  ebvector Z(X.size, X.vector);
  for (int j=0; j<X.size; j++) {
    Z.vector[j] = X.vector[j] + Y.vector[j];
  };
  return Y;
};
