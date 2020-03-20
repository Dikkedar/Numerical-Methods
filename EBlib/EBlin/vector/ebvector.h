#include <iostream>
using namespace std;

class ebvector {
private:
  int N; // size
  double* data; // keep the data as a pointer
public:
  ebvector(int size) { // constructor that sets all data=0
    for (int j=0; j<size; j++) {
      //data[j] = 0;
    };
  };
};
