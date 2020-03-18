#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Silly document for practicing strings and vectors!

vector<int> FindLetters(string InpString, string searchLetter) {
  // Function that returns vector with indices where searchLetter occurs in inpString
  vector<int> Indices;
  int newInd = 0;

  // Workaround to ensure first letter also is checked
  if (InpString.find(searchLetter) == 0) Indices.push_back(0);

  while (newInd != -1) { // If .find() fails to find the letter, it returns -1
    newInd = InpString.find(searchLetter,newInd+1);
    Indices.push_back(newInd); // push_back() is the vector method for appending
  };
  Indices.pop_back(); // Remove the last -1
  return Indices;
};

int FindFunctionDim(string FunctionDefinition) {
  // Finds the amount of variables in a function
  // Variables must be declared as x[0], x[1], ...
  vector<int> VarVec;
  // This should suffice as long as you don't use "x[" other than for variables
  VarVec = FindLetters(FunctionDefinition, "x[");
  return VarVec.size();
};

int FindFunctionParamDim(string FunctionDefinition) {
  // Finds amount of parametres in a function
  // Parameters must be declared as C[0], C[1], ...
  vector<int> ParVec;
  // This should suffice as long as you don't use "x[" other than for variables
  ParVec = FindLetters(FunctionDefinition, "C[");
  return ParVec.size();
};

int main() {
  string MyString = "Hello World!";
  cout << MyString << endl;
  cout << MyString[2] << endl; // Pickout single characters

  // String utilities
  int k; int L;
  k = MyString.find("l"); // Finds first index of "l"
  L = MyString.length();
  cout << k << endl;
  cout << L << endl;

  // Find all l's in a string
  vector<int> lIndices;
  lIndices = FindLetters(MyString, "l");

  // Range based for loop, identical to  "for n in vector:"  in python
  cout << "\nPrinting contents of vector:" << endl;
  for (auto i: lIndices) cout << i << endl;
  cout << endl;

  int NVar; int NPar;
  string MyFunctionDefinition = "C[0]*x[0]*2-x[1]/C[1]+C[2]";
  NVar = FindFunctionDim(MyFunctionDefinition);
  NPar = FindFunctionParamDim(MyFunctionDefinition);
  cout << "Nvar = " << NVar << ", NPar = " << NPar << endl;

  cout << "\nStack and queue testing" << endl;
  stack<int> MyStack;
  queue<double> MyQueue;
  int g = 64;
  double h1 = 2.4; double h2 = 4.3;
  MyStack.push(g);
  MyQueue.push(h1);
  MyQueue.push(h2);
  int myg = MyStack.top();
  double myh1 = MyQueue.front();
  MyQueue.pop();
  double myh2 = MyQueue.front();
  cout << myg << ", " << myh1 << ", " << myh2 << endl;


  char testchar = 'h';
  if (testchar == '(') cout << "yup" << endl;
  else cout << "nop" << endl;


  return 0;
};
