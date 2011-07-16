#include <iostream>
using namespace std;

int BinaryUpperBound(int *arr, int b, int e, int key) {
  if (!arr || b > e) return -1;
  int result = -1;
  int mid = 0;
  while (b <= e) {
    //cout << "b " << b << " e " << e << endl;
    mid = b + (e - b) / 2;
    if (key >= arr[mid]) {
      if (key == arr[mid])
        result = mid;
      b = mid + 1;
    }
    else
      e = mid - 1;
  }
  return result;
}


int main() {
  int arr[100];
  while (cin) {
    cout << endl;
    cout << "Please input array" << endl;
    int i = 0;
    int t = 0;
    while (cin, cin >> t) {
      arr[i++] = t;
    }
    cin.clear();
    cout << "\nPlease input key" << endl;
    int key = 0;
    cin >> key;
    int ret = BinaryUpperBound(arr, 0, i - 1, key);
    if (ret >=0)
      cout << "Found upper bound at index: " << ret << endl;
    else
      cout << "Can't find key " << key << endl;
  }
}
