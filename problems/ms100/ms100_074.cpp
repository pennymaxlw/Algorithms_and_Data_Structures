#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// all ith, f, r, p use absolute index
int Partition(vector<int> &v, int f, int r) {
  int p = f + rand() % (r - f);
  swap(v[p], v[r]);
  int i = f, k = f;
  for (; i < r; ++i) {
    if (v[i] <= v[r])
      swap(v[i], v[k++]);
  }
  swap(v[r], v[k]);
  return k;
}

// all ith, f, r, p use absolute index
int FindNumMoreHalfAux(vector<int> &v, int ith, int f, int r) {
  if (f >= r) return -1;
  int p = Partition(v, f, r);
  //cout << "ith " << ith << " f " << f << " r " << r << " p " << p << endl;
  int ret = 0;
  if (p == ith)
    return v[ith];
  else if (ith < p)
    ret = FindNumMoreHalfAux(v, ith, f, p - 1);
  else
    ret = FindNumMoreHalfAux(v, ith, p + 1, r);
  return ret;
}

int FindNumMoreHalf(vector<int> &v) {
  int size = v.size();
  if (size <= 1) return -1;
  srand(time(NULL));
  return FindNumMoreHalfAux(v, size/2, 0, size - 1);
}

int FindNumMoreHalfScan(vector<int> &v) {
  int size = v.size();
  if (size <= 1) return -1;
  int num = -1;
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (count == 0) {
      num = v[i];
      ++count;
    } else {
      if (v[i] != num)
        --count;
      else
        ++count;
    }
  }
  return num;
}

int main() {
  int arr[] = {5,4,5,5,2,5,2,5,6,5,5,1};
  //int arr[] = {3,3,3,4,4};
  //int arr[] = {2,2};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  cout << "The number which more than half is: "
       //<< FindNumMoreHalf(v) 
       << FindNumMoreHalfScan(v) 
       << endl;
} 
