#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int FindBadNumber(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    while (v[i] != i + 1) {
      if (v[i] > v.size() || v[i] < 1)
        return v[i];
      if (v[i] == v[v[i] - 1])
        return v[i];
      swap(v[i], v[v[i] - 1]);
    }
  }
  return -1;
}


int main() {
  vector<int> v;
  for (int i = 1; i <= 50; ++i) {
    v.push_back(i);
  }
  v[0] = -1;
  random_shuffle(v.begin(), v.end());
  cout << "Bad number is: " << FindBadNumber(v) << endl;
}
