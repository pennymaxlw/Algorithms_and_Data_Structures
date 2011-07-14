#include <iostream>
using namespace std;

void PrintRangeNums(int i, int j) {
  cout << "Found: ";
    for (int k = i; k <= j; ++k) {
      cout << k << " ";
    }
  cout << endl;
}


void FindContinuousNums(int n) {
  if (n < 3) return;
  int i = 1, j = 2;
  int up = (n + 1) / 2;
  int sum = i + j;
  while (i< j && j <= up) {
    if (sum == n) {
      PrintRangeNums(i, j);
      sum -= i;
      ++i; 
      ++j;
      sum += j;
    } else if (sum < n) {
      ++j;
      sum += j;
    } else {
      sum -= i;
      ++i;
    }
  }
}


int main() {
  while (cin) {
    cout << endl;
    cout << "Please input n" << endl;
    int n = 0;
    cin >> n;
    FindContinuousNums(n);
  }
}
