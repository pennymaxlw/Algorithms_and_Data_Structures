#include <iostream>
#include <vector>
using namespace std;

int LowerBound(vector<int> &v, int key) {
  if (v.size() < 1) return -1;
  int l = 0, h = v.size() - 1, m = 0;
  int ret = -1;
  while (l <= h) {
    m = l + (h - l) / 2;
    if (key <= v[m]) {
      if (v[m] == key)
        ret = m;
      h = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ret;
}

int UpperBound(vector<int> &v, int key) {
  if (v.size() < 1) return -1;
  int l = 0, h = v.size() - 1, m = 0;
  int ret = -1;
  while (l <= h) {
    m = l + (h - l) / 2;
    if (key >= v[m]) {
      if (v[m] == key)
        ret = m;
      l = m + 1;
    } else {
      h = m - 1;
    }
  }
  return ret;
}


int main() {
  //int arr[] = {0,2,3,3,3,10,10};
  int arr[] = {2,2,2,2,2,2,2,2,2,2,2,2,3,3,3};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  int key = 3;
  int lower = LowerBound(v, key);
  int upper = UpperBound(v, key);
  cout << "key " << key << " (" << lower << ", " << upper << ")" << endl;
}
