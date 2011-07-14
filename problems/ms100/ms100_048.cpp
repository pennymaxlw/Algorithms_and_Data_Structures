#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(const vector<int> &v, int key) {
  if (v.empty()) return false;
  vector<int>::const_iterator itleft = v.begin(), itright = v.end() - 1;
  vector<int>::const_iterator itmid;
  while (itleft <= itright) {
    itmid = itleft + (itright - itleft) / 2;
    //cout << "left " << *itleft << " right " << *itright;
    //cout << " mid " << *itmid << endl;;
    if (key == *itmid) return true;
    // only one side subarray is a monotonous array
    if (*itmid <= *itleft) {
      if (key > *itmid) {
        if (key == *itleft) 
          return true;
        if (key > *itleft) 
          itleft = itmid + 1;
        else 
          itright = itmid - 1;
      } else
        itleft = itmid + 1;
    }
    else {
      if (key < *itmid) {
        if (key == *itright) 
          return true;
        if (key < *itright) 
          itright = itmid - 1;
        else 
          itright = itmid + 1;
      } else
        itright = itmid - 1;
    }
  }
  return false;
}


int main() {
  //int arr[] = {6,5,4,3,2,1,10,9,8,7};
  //int arr[] = {9,8,7,6,5,4,3,2,1,10};
  //int arr[] = {10};
  //vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  vector<int> v;
  int key = 0;
  while (cin) {
    cout << "Please input key" << endl;
    cin >> key;
    if (BinarySearch(v, key))
      cout << "Found " << key << " in array!" << endl;
    else
      cout << "Did NOT Find " << key << " in array!" << endl;
    cout << endl;
  }
}
