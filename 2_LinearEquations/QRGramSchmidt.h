#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include "MatrixUtilities.h"
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
     The orthogonalized vectors q_i make up the columns of Q
     R is then calculated by A=QR => R = Q^T * A
  */
  cout << "DEBUG TESING" << endl;
  TMatrixD QProto(N,M); // Array containing the orthogonalized vectors

  // Set the first Q-vector
  TMatrixDColumn(QProto,0) = TMatrixDColumn(AMat,0);
  QProto.Print();

  // Collect column vectors in AMat
  for (int i = 1; i < M; i++) { // Loop over columns
    TMatrixD a(N,1);  // The column in A
    TMatrixDColumn(a,0) = TMatrixDColumn(AMat,i);

    // Calculate the orthogonalized vectors
    TMatrixD ProjSum(N,1);

    for (int l = 0; l < i; l++) {
      TMatrixD NewProj(N,1);
      TMatrixDColumn(NewProj,0) = TMatrixDColumn(QProto,l);
      ProjSum += VectorProjectionMatrix(NewProj, a);
      cout << "\n i =" << i << ", l = " << l << endl;
    };

    TMatrixD q(N,1);  // The column in Q
    q = a - ProjSum;

    cout << "Test! i=" << i << ", q=";
    q.Print();
    TMatrixDColumn(QProto,i) = TMatrixDColumn(q,0);
  };

  QMat = QProto;

  // Calculate RMat
  RMat = QMat.T()*AMat;
};








// LEGACY CODE
/*
void QRDecomposition::GramSchmidtOld() {
  cout << "DEBUG TESING" << endl;
  TVectorD QVecs[M]; // Array containing the orthogonalized vectors

  // Collect column vectors in AMat
  for (int i = 0; i < M; i++) { // Loop over columns
    QVecs[M].ResizeTo(N);
    TVectorD a(N);  // The column in A
    TVectorD q(N);  // The column in Q

    for (int j = 0; j < N; j++) a[j] = TMatrixDColumn(AMat,i)[j]; // Fill vector

    // Calculate the orthogonalized vectors
    TVectorD ProjSum(N);
    for (int l = 0; l < i-1; l++) {
      ProjSum += VectorProjection(QVecs[l], a);
    };

    q = a - ProjSum;
    QVecs[i] = q; // Save them in the array
  };

  // Set new QMat
  for (int i = 0; i < M; i++) { // Loop over columns
    for (int j = 0; j < N; j++) { // Loop over entries in each column
      TMatrixDColumn(QMat,i)[j] = QVecs[i][j];
    };
  };

  // Calculate RMat
  RMat = QMat.T()*AMat;
};
*/
















void QRDecomposition::Householder() {
};

void QRDecomposition::Givens() {
};
