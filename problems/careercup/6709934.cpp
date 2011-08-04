#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void PrintNumsWithSum(int n, int currsum, int first, vector<int> &result) {
  if (currsum < 0 || n <= 0)
   return;
  if (currsum == 0) {
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  } else {
    for (int i = first; i <= n; ++i) {
      result.push_back(i);
      PrintNumsWithSum(n, currsum - i, i, result);
      result.pop_back();
    }
  }
}


int main() {
  int n = 0;
  while (cin) {
    cout << "Input n" << endl;
    cin >> n;
    cout << "Results:" << endl;
    vector<int> r;
    PrintNumsWithSum(n, n, 1, r);
  }
}
