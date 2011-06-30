#include <iostream>
using namespace std;

int FibonacciRecursive(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else 
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

int FibonacciIterative(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else {
    int s0 = 0, s1 = 1, tmp;
    int i = 2;
    while (i++ <= n) {
      tmp = s1;
      s1 = s0 + s1;
      s0 = tmp;
    }
    return s1;
  }
}


int main() {
  int n = 10;
  cout << "FibonacciRecursive " << n << " = " << FibonacciRecursive(n) << endl;;
  cout << "FibonacciIterative " << n << " = " << FibonacciIterative(n) << endl;;
}
