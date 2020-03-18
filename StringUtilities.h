#include <iostream>
#include <vector>
using namespace std;



double EvaluateRPN(string inpRPN) {
  double val = 0;
  return val;
};

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
