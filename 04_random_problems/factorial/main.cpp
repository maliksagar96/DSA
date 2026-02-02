/*
  This simple implementation is to develop the understanding of call stack. 
  Call stack keeps track of the active function calls. 
  It works like this:
  suppose we call factorial(3)
  1) This is the first stack => factorial(3). This calls factorial(2).
  2) Second stack => factorial(2).This calls factorial(1).
  3) Third stack => factorial(1). Returns 1 and Delete stack. 
  4) 2 * factorial(1) = 2 * 1. Return 2 and delete stack. 
  5) And so on. 
*/

#include <iostream>

using  namespace std;

int factorial(int n) {
  if(n == 1) return 1;
  else{ return (n) * factorial(n-1);}
}

int main() {

  int n = 6;
  cout<<factorial(n)<<endl;

}