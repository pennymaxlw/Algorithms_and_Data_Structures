#include <iostream>
using namespace std;

bool CheckContinuousArray(int arr[5]) {
  int min = -1, max = -1;
  for (int i = 0; i < 5; ++i) {
    if (arr[i] == 0) continue;
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
  }
  if (min == -1 || max == -1)
    return true;
  else
    return (max - min <= 4);
}


int main() {
  //int arr[5] = {10,7,5,0,6};
  int arr[5] = {0,0,0,0,6};
  if (CheckContinuousArray(arr))
    cout << "YES";
  else
    cout << "No";
  cout << endl;
}
