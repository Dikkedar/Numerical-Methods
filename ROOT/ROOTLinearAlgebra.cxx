#include <iostream>
#include <cmath>

#include <TMath.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TMatrixD.h>
#include <TArrayD.h>
#include <TRandom3.h>
#include <TMatrixDEigen.h>
#include <TVectorD.h>
using namespace std;

/*
    TESTING GROUNDS FOR THE LINEAR ALGEBRA CAPABILITIES IN ROOT
    Consult chapters 15-17 of the user's guide!
*/

// Prototyping functions
void vecPrint(TVector3 Q);
void vecsfPrint(TVector3 Q);

int main() {
  /*
      Cartesian 3-vector utilities
      https://root.cern.ch/doc/master/classTVector3.html
  */
  cout << "\nVECTOR GYMNASTICS\n" << endl;
  TVector3 a(1.0, 0.0, 0.0); // 3-dimensional vector
  TVector3 b(0.5, 1.2, 2.1);
  TVector3 c = a+b; // addition of 3-vectors
  double d = a*b; // dot product (also: c.Dot(d))
  vecsfPrint(c);
  TVector3 c2 = c.Unit(); // normaliza to unit length
  c.RotateX(TMath::Pi()); // Also has RotateY and RotateZ
  vecsfPrint(c);

  /*
      Four-vectors and special relativity
      https://root.cern.ch/doc/master/classTLorentzVector.html
  */
  // Four-vector, (x,y,z,t) with Minkowski signature {-,-,-,+}
  TLorentzVector V(1.0, 0.0, 0.0, 1.0);
  TVector3 v = V.Vect(); // get spatial components
  vecPrint(v);
  TLorentzVector W(0.2, 0.8, 0.0, 1.2);
  double Z = V.Dot(W); // four-vector dot product
  // Rotations are the same as for TVector3
  V.Boost(0.8, 0.0, 0.0); // Lorentz boost, inputs are ???
  vecPrint(V.Vect());

  // Another useful class is the N-vector of TVectorD
  TVectorD Y[7];
  Y[2] = 3.0; Y[6] = 0.1; // How to fill


  /*
      BASIC MATRICES
      https://root.cern.ch/root/htmldoc/guides/users-guide/LinearAlgebra.html
  */
  // TMatrixD for dense matrices, TMatrixS for sparse matrices, TMatrixDSym also
  cout << "\nMATRIX GYMNASTICS\n" << endl;
  TMatrixD A(3,4); // Creates empty matrix of dimension 3x4
  cout << "Rows: " << A.GetNrows() << endl;
  cout << "Columns: " << A.GetNcols() << endl;

  // How to fill a matrix with data (fills rows first by default)
  const double MatData[3*4] = {1,2,3,4,5,6,7,8,9,10,11,12};
  A.SetMatrixArray(MatData); // or
  Option_t *MatOpt;
  //Option_t *MatOpt = new Option_t("F");
  MatOpt = "F";
  A.SetMatrixArray(MatData, MatOpt);
  // A.Print(); // How to print a matrix nicely!

  // Create a random matrix to showcase the following with
  // Also done by B.Randomize(min,max,seed) method (uniform dist.)
  int MatSize = 25;
  double MatDataRand[MatSize]; // Initialize array to hold data
  TRandom3 Rand; // Load random module
  Rand.SetSeed(0); // Need to set a seed for unique random values
  Rand.RndmArray(MatSize, MatDataRand); // Save random values in array
  TMatrixD B(5,5); // Initialize matrix (empty)
  B.SetMatrixArray(MatDataRand); // Set matrix data
  B.Print();

  // Filling matrix using the TArrayD class
  TArrayD MatData1(MatSize); // Initialize TArrayD class
  for (int j=0; j < MatSize; j++) MatData1[j] = Rand.Rndm(); // Fill array
  TMatrixD C(5,5);
  C.SetMatrixArray(MatData1.GetArray()); // Need .GetArray() method on TArrayD
  // C.Print();

  // Quick way to create identity matrix
  TMatrixD I; I.UnitMatrix();
  TMatrixD O; O.Zero(); // Fast zero matrix

  // Matrix operations
  TMatrixD D = C + B; // Matrix addition
  TMatrixD E = D * B; // Matrix multiplication
  double alpha = 0.5;
  E *= alpha*E; // Multiply E (matrix) by alpha (scalar)

  // How to multiply (matrix,vector)
  TMatrixD myVec(5,1); // Vectors as 5x1 matrices
  double vData[5] = {1.0, 0.6, 4.0, 2.3, 4.7};
  myVec.SetMatrixArray(vData);
  TMatrixD N = C*myVec; // Multiply matrix onto vector

  E.T(); // Transpose
  E.Invert(); // Inverse matrix

  // Eigenvectors and eigenvalues
  TMatrixDEigen eigE(B); // Create a eigen-type class loaded with the matrix B

  cout << "\nEIGENVALUES";
  TMatrixD Eeigvals = eigE.GetEigenValues(); // Saves eigenvalues along diagonal
  Eeigvals.Print();

  cout << "\nEIGENVECTORS";
  TMatrixD Eeigvecs = eigE.GetEigenVectors(); // Saves eigenvectors in matrix
  Eeigvecs.Print();

  // Matrix views (operations on separate rows/columns etc.)
  TMatrixDRow myRow = TMatrixDRow(E,0); // Save first row of E
  TMatrixDRow(E,3) = myRow; // Sets third row of E to myRow
  TMatrixDColumn myCol = TMatrixDColumn(E,4); // Save fifth column of E



  return 0;
}

// Simple function to print TVector3 for debugging
void vecPrint (TVector3 Q) {
  cout << "x=" << Q.X() << " y=" << Q.Y() << " z=" << Q.Z() << endl; // get entries
}
// Spherical version
void vecsfPrint (TVector3 Q) {
  cout << "rho=" << Q.Mag() << " theta=" << Q.Theta() << " phi=" << Q.Phi() << endl; // get spherical components
}
