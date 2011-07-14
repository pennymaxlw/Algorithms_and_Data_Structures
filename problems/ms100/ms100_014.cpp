#include <iostream>
using namespace std;

void FindPairSum(int *arr, int size, int sum) {
  int *rarr = new int[size];
  for (int i = 0; i < size; ++i) {
    rarr[i] = sum - arr[size - i - 1];
  }
  int i = 0, j = 0;
  while (i < size && j < size) {
    if (arr[i] < rarr[j]) 
      i++;
    else if (arr[i] > rarr[j])
      j++;
    else {
      cout << "Found pair: " << arr[i]
        << " " << sum - arr[i] << endl;
        i++; j++;
    }
  }

  delete [] rarr;
}

int main() {
  int arr[] = {1,2,3,4,5};
  FindPairSum(arr, sizeof(arr)/sizeof(int), 6);
}
