#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void Solve(const vector<int> &buckets, vector<int> &ret, int n, int bucket) {
  if (buckets.size() != ret.size())
    return;
  if (n < 0)
    return;
  else if (n == 0) {
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ""));
    cout << endl;
  } else {
    for (int i = bucket; i < buckets.size(); i++) {
      if (ret[i] < buckets[i]) {
        ret[i]++;
        Solve(buckets, ret, n - 1, i);
        ret[i]--;
      }
    }
  }
}


int main() {
  vector<int> buckets;
  int n, s;
  while (cin) {
    cout << "Input buckets size:" << endl;
    cin >> s;
    cout << "Input buckets:" << endl;
    while (s--) {
      cin >> n;
      buckets.push_back(n);
    }
    cout << "Input total:" << endl;
    cin >> n;
    vector<int> ret(buckets.size(), 0);
    cout << "Results:" << endl;
    Solve(buckets, ret, n, 0);
    cout << endl;
  }
}
