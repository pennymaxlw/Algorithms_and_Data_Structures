#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

list<int> ls;
void FindSum(int sum, int n) {
  if (sum < 0 || n < 0)
    return;
  else if (sum > 0) {
    ls.push_front(n);
    FindSum(sum - n, n - 1);
    ls.pop_front();
    FindSum(sum, n - 1);
  } else {
    copy(ls.begin(), ls.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}

void FindSum2(int sum, int n, int cur) {
  if (sum < 0)
    return;
  else if (sum == 0) {
    copy(ls.begin(), ls.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  } else {
    for (int i = cur; i <= n; i++) {
      ls.push_back(i);
      FindSum2(sum - i, n, i + 1);
      ls.pop_back();
    }
  }
}

int main() {
  int n = 5;
  int m = 7;
  FindSum(m, n);
  cout << "--------" << endl;
  FindSum2(m, n, 1);
}
