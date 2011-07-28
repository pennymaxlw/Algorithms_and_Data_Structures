#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int MinInLeftRotatedArr(vector<int> &v) {
  int size = v.size();
  if (size == 0) return -1;
  if (size == 1) return v[0];
  int i = 0, j = size - 1, mid = 0;
  while (i <= j) {
    //cout << v[i] << " " << v[j] << endl;
    mid = i + (j - i) / 2;
    if (v[i] > v[mid]) {
      j = mid;
    } else if (v[mid] > v[j]) {
      i = mid + 1;
    } else {
      break;
    }
  }
  return v[i];
}

int MinInLeftRotatedArr2(vector<int> &v) {
  int size = v.size();
  if (size < 1) return -1;
  if (size == 1) return v[0];
  int l = 0, r = v.size() - 1, m = 0;
  int minval = v[0];
  while (l <= r) {
    m = l + (r - l) / 2;
    if (v[l] <= v[m]) {
      minval = min(v[l], minval);
      l = m + 1;
    } else if (v[m] <= v[r]) {
      minval = min(v[m], minval);
      r = m - 1;
    }
  }
  return minval;
}


int main() {
  vector<int> orig;
  for (int i = 1; i <= 1000; ++i)
    orig.push_back(i);
  for (int i = 0; i < orig.size(); ++i) {
    vector<int> v(orig.begin(), orig.end());
    rotate(v.begin(), v.begin() + i, v.end());
    int min = MinInLeftRotatedArr2(v);
    if (min != 1) {
      copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
      cout << "Min in array: " << min << endl;
    } else {
      cout << min << " ";
    }
  }
  cout << endl;
}
