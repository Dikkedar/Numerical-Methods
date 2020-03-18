#include <iostream>
#include "../2_LinearEquations/QRDecomposition.h"
// ../MatrixUtilities.h is imported through QRDecomposition.h
using namespace std;

TMatrixD LeastSquaresQR(TMatrixD AMat, TMatrixD bvec) {
  // Solves the least squares problem, i.e. finds best c such that Amat*c=b
  QRDecomposition QRA(AMat);
  QRA.GramSchmidt();
  TMatrixD R;
  R = QRA.RMat;

  


};
