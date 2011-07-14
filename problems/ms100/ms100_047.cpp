#include <iostream>
#include <vector>
using namespace std;

int FindMaxDecreasingArray(vector<int> &v) { 
  if (v.empty()) return 0;
  int size = v.size();
  vector<int> record(size, 1);
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < i; ++j)
      if (v[i] < v[j] && record[j] + 1 > record[i])
          record[i] = record[j] + 1;
  return record[size - 1];
} 


int main() {
  int arr[] = {9,4,3,2,5,4,3,2,1};
  //int arr[] = {4};
  vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
  cout << "Max decreasing array length: "
       << FindMaxDecreasingArray(v) << endl;
}
