#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void MakeOddEven(vector<int> &in)
{
  vector<int>::iterator first = in.begin();
  vector<int>::iterator last = in.end() - 1;

  while (1)
  {
    while ((*first) % 2 == 1) ++first;
    while ((*last) % 2 == 0) --last;
    if (first < last) 
      swap(*first++, *last--);
    else 
      return;
  }
}


int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  //int arr[] = {2,4,6,8,10,1,3,5,7,9};
  vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
  MakeOddEven(v);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " " ));
  cout << endl;
}
