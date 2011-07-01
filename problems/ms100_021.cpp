#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

list<int> ls;
void FindSum(int sum, int n) {
  if (sum < 1 || n < 1) return;
  if (sum > n) {
    ls.push_front(n);
    FindSum(sum - n, n - 1);
    ls.pop_front();
    FindSum(sum, n - 1);
  } else {
    cout << sum << " ";
    copy(ls.begin(), ls.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}

int main() {
  int n = 5;
  int m = 7;
  FindSum(m, n);
}
