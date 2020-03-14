#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
//#include "MatrixUtilities.h"
using namespace std;

/*
    QR Decompositions of a matrix based on different algorithms
    http://62.107.14.89/~fedorov/old/prog-2019/numeric/book/lineq.pdf

    Goal: Write arbitrary matrix A as
          A = QR,
    where Q is an orthogonal matrix and R is an upper triangular matrix.
*/

// Make output class to contain both A, Q and R matrices
// Implement the decomposition algorithms as member functions
class QRDecomposition {
public:
  TMatrixD AMat;
  TMatrixD QMat;
  TMatrixD RMat;
  int N;
  int M;

  QRDecomposition(TMatrixD inpMat) {
    N = inpMat.GetNrows();
    M = inpMat.GetNcols();
    AMat.ResizeTo(N,M);
    QMat.ResizeTo(N,M);
    RMat.ResizeTo(N,M);
    AMat = inpMat;
  };

  // Implementation of the algorithms for creating the decomposition
  void GramSchmidt();
  void Householder();
  void Givens();
};

/*
    Implementation of decomposition algorithms

*/

void QRDecomposition::GramSchmidt() {
  /*
     Decomposition by Gram Schmidt orthogonalization of column vectors a_i in AMat
     The orthogonalized vectors q_i make up the orthogonal Q
     R is then calculated by A=QR => R = Q^T * A
  */

  TMatrixD QProtoMat(N,M);

  // Collect column vectors in AMat
  for (int i = 0; i < M; i++) {
    TVectorD a[N];  // The column in A
    TVectorD q[N];  // The column in Q

    for (int j = 0; j < N; j++) a[j] = TMatrixDColumn(AMat,i)[j]; // Fill vector



    //TMatrixDColumn(QProtoMat, i) = 0;
  };


  cout << "Test!" << endl;
};


























void QRDecomposition::Householder() {
};

void QRDecomposition::Givens() {
};
