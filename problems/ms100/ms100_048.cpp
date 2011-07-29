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

bool BinarySearch2(vector<int> &v, int key) {
  if (v.empty()) return false;
  int l = 0, r = v.size() - 1, m = 0;
  while (l <= r) {
    //cout << "l " << l << " r " << r << endl;
    m = l + (r - l) / 2;
    if (v[m] == key) return true;
    if (key > v[m]) {
      if (v[l] >= v[m] && key > v[l]) // abstract from below
        l = m + 1;
      else
        r = m - 1;
    } else {
      if (v[l] >= v[m]) // left mono
        l = m + 1;
      else if (key >= v[r])
        l = m + 1;
      else
        r = m - 1;
    }
  }
  return false;
}

bool BinarySearch3(vector<int> &v, int key) {
  if (v.empty()) return false;
  int l = 0, r = v.size() - 1, m = 0;
  while (l <= r) {
    //cout << "l " << l << " r " << r << endl;
    m = l + (r - l) / 2;
    if (v[m] == key) return true;
    if (v[l] >= v[m]) {
      if (v[l] >= key && key > v[m])
        r = m - 1;
      else
        l = m + 1;
    } else {
      if (v[m] > key && key >= v[r])
        l = m + 1;
      else
        r = m - 1;
    }
  }
  return false;
}

int main() {
  int arr[] = {6,5,4,3,2,1,10,9,8,7};
  //int arr[] = {9,8,7,6,5,4,3,2,1,10};
  //int arr[] = {10};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  //vector<int> v;
  for (int i = 0; i < v.size(); ++i) {
    if (!BinarySearch3(v, v[i])) {
      cout << "NOT found " << v[i] << endl;
      return 0;
    }
  }
  cout << "\nFound All!" << endl;
}
