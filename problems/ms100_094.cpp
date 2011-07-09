#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iterator>
using namespace std;

int MaxArithmeticArray(vector<int> &v, int &start, int &diff) {
  int size = v.size();
  if (size < 0) return -1;
  sort(v.begin(), v.end());
  int i = 0, j = 0, k = 0;
  int len = 0, maxlen = 0;
  int df = 0;
  int pre = 0;
  for (i = 0; i < size; ++i) {
    for (j = i + 1; j < size; ++j) {
      df = v[j] - v[i];
      len = 2;
      pre = v[j];
      for (k = j + 1; k < size; ++k) {
        if (v[k] == pre + df) {
          len += 1;
          pre = v[k];
        }
      }
      if (len > maxlen) {
        maxlen = len;
        start = i;
        diff = df;
        if (maxlen >= 3) {
          cout << "Max length arithmetic Array is:" << endl;
          for (int m = 0; m < maxlen; ++m)
            cout << v[start] + m * diff << " ";
          cout << endl;
        }
      }
    }
  }
  return maxlen; 
}


int main() {
  srand(time(NULL));
  int n = 0, maxlen = 0, start = 0, diff = 0;
  int i = 0;
  while (cin) {
    cout << endl;
    cout << "Please input the array length" << endl;
    cin >> n;
    vector<int> v(n, 0);
    for (i = 0; i < n; ++i) {
      v[i] = rand() % 10;
    }
    cout << "Input array is: " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    maxlen = MaxArithmeticArray(v, start, diff);
  }
}
