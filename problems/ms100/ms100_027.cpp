#include <iostream>
using namespace std;

int JumpSum(int n) {
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  return JumpSum(n-1) + JumpSum(n-2);
}

int JumpSumDP(int n) {
  if (n < 0) return -1;
  if (n == 1) return 1;
  if (n == 2) return 2;
  int s0 = 1, s1 = 2, s;
  int i = 3;  //Caution i is not start from 0 or 1
  while (i <= n) {
    s = s0 + s1;
    s0 = s1;
    s1 = s;
    ++i;
  }
  return s;
}

int main() {
  int i;
  cin >> i;
  cout << "Possible solutions: " << JumpSumDP(i) << endl;
}
