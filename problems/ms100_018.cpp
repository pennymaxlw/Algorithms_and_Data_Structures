#include <iostream>
using namespace std;

int Josephus(int n, int m) {
  if (n < 1 || m < 1) return -1;
  int last = 0;
  for (int i = 2; i <= n; ++i) {
    last = (last + m) % i;
  }
  return last + 1;
}


int main() {
  int n, m;
  cin >> n;
  cin >> m;
  cout << "Last one for n " << n << " m " << m 
    << " is " << Josephus(n, m) << endl;
}
