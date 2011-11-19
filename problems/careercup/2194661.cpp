#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <queue>
using namespace std;
// First part: odd number descending
// Second part: even number ascending

// Overwrite comparison method
bool compare(int i, int j) {
  if ((i&1) == 0 && (j&1) == 0)
    return i < j;
  else if ((i&1) == 1 && (j&1) == 1)
    return i > j;
  else
    return ((j&1) == 0);
}
void Solve1(vector<int> &v) {
  sort(v.begin(), v.end(), compare);
}

// Partition then sort two parts
bool IsOdd(int i) {return ((i&1) == 1);}
void Solve2(vector<int> &v) {
  vector<int>::iterator bound = partition(v.begin(), v.end(), IsOdd);
  sort(v.begin(), bound, greater<int>());
  sort(bound, v.end(), less<int>());
}

// Using Max heap and Min heap
void Solve3(vector<int> &v) {
  priority_queue<int, vector<int>, less<int> > oddheap;
  priority_queue<int, vector<int>, greater<int> > evenheap;
  for (int i = 0; i < v.size(); i++) {
    if ((v[i]&1) == 0)
      evenheap.push(v[i]);
    else
      oddheap.push(v[i]);
  }
  int i = 0;
  while (!oddheap.empty()) {
    v[i++] = oddheap.top();
    oddheap.pop();
  }
  while (!evenheap.empty()) {
    v[i++] = evenheap.top();
    evenheap.pop();
  }
}


int main() {
  int a[] = {1,2,3,4,5,6,7,8,9};
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  Solve2(v);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
