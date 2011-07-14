#include <iostream>
using namespace std;

int Count1(unsigned int n) {
  int mask = 1;
  int count = 0;
  while (n) {
    if (n & mask) ++count;
    n = n >> 1;
  }
  return count;
}

int Count1A(int i) {
  int mask = 1;
  int count = 0;
  while (mask) {
    if (mask & i) ++count;
    mask = mask << 1;
  }
  return count;
}

int main() {
  int i = 0;
  cin >> i;
  cout << hex << showbase << i << endl;
  cout << dec << noshowbase;
  cout << i << " has " << Count1(i) << " number of 1" << endl;
  cout << i << " has " << Count1A(i) << " number of 1" << endl;
}
