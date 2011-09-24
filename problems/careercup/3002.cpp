#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

unsigned long steps = 0;

bool InPlaceShuffle(vector<int> &v) {
  typedef vector<int>::size_type SIZE;
  SIZE size = v.size();
  if (size < 1) return false;
  if (size % 2 == 1) return false;
  int min = *min_element(v.begin(), v.end()); 
  int max = *max_element(v.begin(), v.end());
  int diff = max - min + 1;
  cout << "diff: " << diff << endl;
  SIZE n = size / 2; 
  int tmp = 0;
  for (SIZE i = 0, k = 0; i < size; i++) {
    steps++;
    if (v[i] > max)
      continue;
    k = i;
    tmp = v[i];
    while (true) {
      steps++;
      if (k < n) k = 2 * k;
      else k = 2 * (k % n) + 1;
      if (v[k] > max)
        break;
      swap(tmp, v[k]);
      v[k] += diff;
    }
  }
  transform(v.begin(), v.end(), v.begin(), bind2nd(minus<int>(), diff));
  return true;
}


int main() {
  vector<int> v;
  const int SIZE = 100000000;
  for (int i = 1; i <= SIZE; i++)
    v.push_back(i);
  for (int i = 1; i <= SIZE; i++)
    v.push_back(-i);
  //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  //cout << endl;
  InPlaceShuffle(v);
  //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  //cout << endl;
  int i = 0;
  for (; i < SIZE - 1; i += 2) {
    if (v[i] != -v[i + 1]) {
      cout << "Verification failed!!!" << endl;
      break;
    }
  }
  if (i == SIZE)
      cout << "Verification passed" << endl;
  cout << "Total steps: " << steps << endl;
  cout << "steps/SIZE: " << steps/(2 * SIZE) << endl;
}
