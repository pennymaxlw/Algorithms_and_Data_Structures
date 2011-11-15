#include <iostream>
#include <vector>
using namespace std;

void PrintAll(int n, int sum, int first, vector<int> &result) {
  if (n < 0)
    return;
  else if (n == 0) {
    if (sum == 0) {
      // if we need to consider all permutations,
      // we could use next_permutaion() here
      cout << "Found: ";
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
      cout << endl;
    }
  } else {
    for (int i = first; i <= sum; i++) {
      result.push_back(i);
      PrintAll(n - 1, sum - i, i, result);   
      result.pop_back();
    }
  }
}

int main() {
  int n = 0;
  int sum = 0;
  vector<int> ret;
  while (cin) {
    cout << "Input n:";
    cin >> n;
    cout << "Input sum:";
    cin >> sum;
    PrintAll(n, sum, 0, ret);
    ret.clear();
  }
}

