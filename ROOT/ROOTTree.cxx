#include <iostream>
#include <TTree.h>
using namespace std;

int main() {
  cout << "Hello World!" << endl;
  TTree MyTree;

  Double_t * TestPtr;

  // Create a branch, constructor is (branchname, firstleafaddress)
  MyTree.Branch("FirstBranch", &TestPtr);


};
