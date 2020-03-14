#include <iostream>
using namespace std;

class ebvector3d {
public:
  double x;
  double y;
  double z;

  ebvector3d(double xinp=0.0, double yinp=0.0, double zinp=0.0) {
    x = xinp;
    y = yinp;
    z = zinp;
  };

  void printVector() {
    cout << x << " " << y << " " << z << endl;
  }

};

ebvector3d operator*(const double a, ebvector3d X) {
  ebvector3d Y(a*X.x, a*X.y, a*X.z);
  return Y;
};

ebvector3d operator+(ebvector3d X, ebvector3d Y) {
  ebvector3d Z(X.x+Y.x, X.y+Y.y, X.z+Y.y);
  return Z;
};
