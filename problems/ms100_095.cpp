#include <cstdio>
using namespace std;

bool IsAscendingArray(int *arr, int n) {
  if (n == 0) return true;
  if (arr[n] > arr[n - 1])
    return IsAscendingArray(arr, n - 1);
  else
    return false;
}


int main() {
  int arr[5] = {1,2,6,4,5};
  if (IsAscendingArray(arr, 4))
    puts("YES");
  else
    puts("NO");
}
