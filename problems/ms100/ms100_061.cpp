#include <iostream>
#include <vector>
using namespace std;

int ArrayXOR(vector<int> &v) {
  if (v.empty()) return 0;
  vector<int>::iterator it = v.begin();
  int result = 0;
  for (; it != v.end(); ++it) {
    result = result ^ *it;
  }
  return result;
}

void FindTwoSingleNumber(vector<int> &v, int &m, int &n) {
  if (v.size() < 2) return;
  int x = ArrayXOR(v);
  int mask = 1;
  int i = 1;
  while (!(x & (mask << i++)));
  vector<int> tmpv1;
  vector<int> tmpv2;
  for (i = 0; i < v.size(); ++i) {
    if (v[i] & mask) tmpv1.push_back(v[i]);
    else tmpv2.push_back(v[i]);
  }
  m = ArrayXOR(tmpv1);
  n = ArrayXOR(tmpv2);
}


int main() {
  int arr[] = {1,20,2,3,4,5,6,6,5,4,11,3,2,1};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  int m = 0, n = 0;
  FindTwoSingleNumber(v, m, n);
  cout << "Two single numbers are: " << m << " " << n << endl;
}
