#include <iostream>
#include <vector>
using namespace std;

bool CheckPostOrder(vector<int> &v, int first, int last) {
  if (first < last || v.empty()) {
    int root = v[last];
    int right_first, left_last;
    int i = last - 1;
    while (v[i] >= root) --i;
    if (i == last - 1) {
      right_first = last - 1;
      left_last = last - 1;
    } else {
      right_first = i + 1;
      left_last = i;
    }
    while (i >= 0 && v[i] < root) --i;
    if (i > -1) 
      return false;
    bool left = true;
    if (left_last > first)
      left = CheckPostOrder(v, first, left_last);
    bool right = true;
    if (right_first < last - 1) 
      right = CheckPostOrder(v, right_first, last -1);
    return left && right;
  } 
  return false;
}

int main() {
  //int arr[] = {5,7,6,9,11,10,8}; //Yes
  //int arr[] = {5,13,6,9,11,10,8}; //No
  //int arr[] = {5,7,6,8}; //Yes
  //int arr[] = {16,8}; //Yes
  int arr[] = {7,4,6,5}; //No
  vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

  if (CheckPostOrder(v, 0, v.size() - 1)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
