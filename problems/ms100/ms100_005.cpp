#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>
using namespace std;

int partition(vector<int> &v, int first, int last) {
  srand(time(NULL));
  int p = first + rand() % (last - first);
  swap(v[p], v[last]);
  int save = first;
  for (int i = first; i < last; ++i) {
    if (v[i] <= v[last])
      swap(v[save++], v[i]);
  } 
  swap(v[save], v[last]);
  return save;
}

void partition_by_ith_elem(vector<int> &v, int first, int last, int i) {
  if (last == first)
    return;       
  int pos = partition(v, first, last);
  int offset = pos - first;
  if (i == offset) {
    return; 
  } else if (i < offset) {
    partition_by_ith_elem(v, first, pos - 1, i);
  } else {
    partition_by_ith_elem(v, pos + 1, last, i - offset - 1);
  }
}

int main() {
  const int SIZE = 20;
  vector<int> v;
  for (int i = 0; i < SIZE; ++i) {
    v.push_back(i);
  }
  random_shuffle(v.begin(), v.end());
  cout << "Initial vector: " << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  int ith = 6;
  partition_by_ith_elem(v, 0, v.size() - 1, ith);

  cout << "First " << ith << " sorted elements: " << endl;
  sort(v.begin(), v.begin() + ith);
  for (int i = 0; i <= ith; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
