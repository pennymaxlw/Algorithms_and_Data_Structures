#include <iostream>
using namespace std;

int Sum(int i) {
  if (i > 0) {
    return Sum(i - 1) + i;
  }
  return 0;
}

int main() {
  int n = 100;
  cout << "Sum " << Sum(100) << endl;
}
