#include <iostream>
#include <vector>
using namespace std;

int MinInLeftRotatedArr(vector<int> &v) {
  int size = v.size();
  if (size == 0) return -1;
  if (size == 1) return v[0];
  int i = 0, j = size - 1, mid = 0;
  int min = v[0];
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


int main() {
  int arr[] = {6,7,8,9,1,2,3,4,5};
  //int arr[] = {7,8,9,1,2,3,4,5,6};
  //int arr[] = {2,3,4,5,1};
  //int arr[] = {6,2,3,4,5};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  int min = MinInLeftRotatedArr(v);
  cout << "Min in array: " << min << endl;
}
