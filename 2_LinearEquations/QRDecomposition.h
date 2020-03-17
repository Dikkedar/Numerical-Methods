#include <iostream>
#include <TMatrixD.h>
#include <TVectorD.h>
#include <TMath.h>
#include "../MatrixUtilities.h"
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
  TMatrixD QTransp;
  TMatrixD RMat;
  int N;
  int M;
  double Tol; // Tolerance, generally sets element to zero if less than this

  QRDecomposition(TMatrixD inpMat) {
    N = inpMat.GetNrows();
    M = inpMat.GetNcols();
    AMat.ResizeTo(N,M);
    QMat.ResizeTo(N,M);
    QTransp.ResizeTo(M,N);
    RMat.ResizeTo(M,M);
    AMat = inpMat;
    Tol = 1e-10;
  };

  // Implementation of the algorithms for creating the decomposition
  void GramSchmidt();
  void Householder();
  void Givens();

  // Utilities given the decompositions
  double Determinant();
  TMatrixD AInverse();
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
  TMatrixD QProto(N,M); // Array containing the orthogonalized vectors

  // Set the first Q-vector
  TMatrixD q1(N,1);
  TMatrixD a1(N,1);
  for (int j = 0; j < N; j++) TMatrixDRow(a1,j)[0] = TMatrixDColumn(AMat,0)[j];
  double q1leninv = 1/VectorDotMatrix(a1,a1);
  q1 = a1;
  q1 *= TMath::Sqrt(q1leninv);
  TMatrixDColumn(QProto,0) = TMatrixDColumn(q1,0);
  double Q;

  // Collect column vectors in AMat
  for (int i = 1; i < M; i++) { // Loop over columns
    TMatrixD a(N,1);  // The column in A
    TMatrixDColumn(a,0) = TMatrixDColumn(AMat,i);

    // Calculate the orthogonalized vectors
    TMatrixD ProjSum(N,1);

    for (int l = 0; l < i; l++) {
      TMatrixD NewProj(N,1);
      TMatrixDColumn(NewProj,0) = TMatrixDColumn(QProto,l);
      ProjSum += VectorProjectionMatrix(a, NewProj);
    };

    TMatrixD q(N,1);  // The column in Q
    q = a - ProjSum;

    // Normalize q
    double qleninv = 1/VectorDotMatrix(q,q);
    q *= TMath::Sqrt(qleninv);

    TMatrixDColumn(QProto,i) = TMatrixDColumn(q,0);

    // Check orthogonality
    TMatrixD PrevCol(N,1);
    TMatrixDColumn(PrevCol,0) = TMatrixDColumn(QProto,i-1);
    double Ocheck = VectorDotMatrix(q,PrevCol);
    // cout << "i = " << i <<", orthogonality check = " << Ocheck << endl;
  };

  QMat = QProto;

  // Calculate RMat
  TMatrixD QTr = Transpose(QMat);
  QTransp = QTr;
  RMat = QTr*AMat;


  // Delete all elements smaller than tolerance in RMat
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (TMath::Abs(TMatrixDRow(RMat,i)[j]) < Tol) TMatrixDRow(RMat,i)[j] = 0.0;
    };
  };
};

void QRDecomposition::Householder() {
};

void QRDecomposition::Givens() {
};

/*
    Other utilities relevant to linear equation solving

*/

TMatrixD BackSubstitution(TMatrixD cvec, TMatrixD U) {
  // Solves  U*yvec = cvec, where U is upper triangular e.g. from QR decomposition
  // Uses back-substitution method, refer to notes
  int N = cvec.GetNrows(); // cvec is a Nx1 matrix, i.e. column vector
  TMatrixD yvec(N,1);

  // See (4) in notes for the formula
  for (int i = N-1; i >= 0; i--) { // Loop over elements in y
    double Uii = TMatrixDRow(U,i)[i];
    double ci = TMatrixDRow(cvec,i)[0];
    double yback = 0.0;
    for (int k = i+1; k < N; k++) {
      double Uik = TMatrixDRow(U,i)[k];
      double yk = TMatrixDRow(yvec,k)[0];
      yback += Uik*yk;
    };
    double newy = (ci-yback)/Uii;
    TMatrixDRow(yvec,i)[0] = newy;
  };

  return yvec;
};

TMatrixD ForwardSubstitution(TMatrixD cvec, TMatrixD L) {
  // Forward substitution, L is lower triangular matrix
  // UNTESTED AS OF 17/3-20!
  int N = cvec.GetNrows(); // cvec is a Nx1 matrix, i.e. column vector
  TMatrixD yvec(N,1);
  // See (5) in notes for the formula
  for (int i = 0; i < N; i++) { // Loop over elements in y
    double Lii = TMatrixDRow(L,i)[i];
    double ci = TMatrixDRow(cvec,i)[0];
    double yback = 0.0;
    for (int k = 0; k < i; k++) {
      double Lik = TMatrixDRow(L,i)[k];
      double yk = TMatrixDRow(yvec,k)[0];
      yback += Lik*yk;
    };
    double newy = (ci-yback)/Lii;
    TMatrixDRow(yvec,i)[0] = newy;
  };
  return yvec;
};

TMatrixD QRSolveGramSchmidt(TMatrixD A, TMatrixD b) {
  // Solve the linear system of equations Ax=b with QR decomposition
  int N = b.GetNrows();
  int M = A.GetNcols();
  TMatrixD x(N,1);

  // Carry out QR decomposition of A
  QRDecomposition QRSolving(A);
  QRSolving.GramSchmidt();

  // Rewrite Ax=b => Rx = Q^T*b
  TMatrixD cvec(N,1);
  cvec = QRSolving.QTransp*b;

  x = BackSubstitution(cvec, QRSolving.RMat);
  return x;
};


/*
    UTILITIES GIVEN DECOMPOSITIONS

*/

double QRDecomposition::Determinant() {
  // Gives the determinant of AMat after decomposition is done
  // With QR Decomposition, only the sign of the determinant can be determined
  // Only works with square matrices
  double det = TMatrixDRow(RMat,0)[0];
  for (int i = 1; i < M; i++) {
    det *= TMatrixDRow(RMat,i)[i];
  };
  return det;
};

TMatrixD QRDecomposition::AInverse() {
  // Returns the inverse of AMat, assuming it is square matrix
  // For method, see 1.5 in notes
  TMatrixD AInv(N,N);
  for (int i = 0; i < N; i++) {
    TMatrixD newCol(N,1);
    TMatrixD newUnit(N,1);
    for (int j = 0; j < N; j++) { // Create unit vector e_i
      if (j == i) TMatrixDRow(newUnit,j)[0] = 1;
      else TMatrixDRow(newUnit,j)[0] = 0;
    };
    newCol = QRSolveGramSchmidt(AMat, newUnit);
    TMatrixDColumn(AInv,i) = TMatrixDColumn(newCol,0);
  };
  return AInv;
};
