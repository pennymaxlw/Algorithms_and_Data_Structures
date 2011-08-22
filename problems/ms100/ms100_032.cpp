#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

void MostLikelySum(vector<int> &v, int cursum, 
                  int refsum, int leftcnt, int first, int &mindiff) {
  if (first >= v.size())
    return;
  if (leftcnt == 0) {
    if (cursum <= refsum) {
      int diff = refsum - cursum;
      mindiff = min(mindiff, diff);
    }
    return; 
  }
  MostLikelySum(v, cursum + v[first], refsum, leftcnt - 1, first + 1, mindiff);
  MostLikelySum(v, cursum, refsum, leftcnt, first + 1, mindiff);
}

void FindSubArrayWithSum(vector<int> &v, int cursum, int refsum, int first,
                         int leftcnt, vector<int> &result) {
  if (first >= v.size())
    return;
  if (leftcnt == 0) {
    if (cursum == refsum) {
      copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    }
    return;
  }
  result.push_back(v[first]);
  FindSubArrayWithSum(v, cursum + v[first], refsum, first + 1, leftcnt - 1, result);
  result.pop_back();
  FindSubArrayWithSum(v, cursum, refsum, first + 1, leftcnt, result);
}

int main() {
  int arr[] = {1,3,7,8,9,15,12,51,43,29};
  vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
  int totalsum = 0;
  totalsum = accumulate(v.begin(), v.end(), totalsum);
  cout << "Total sum: " << totalsum << endl;
  int mindiff = totalsum;
  MostLikelySum(v, 0, totalsum / 2, v.size() / 2, 0, mindiff);
  cout << "minimum diff: " << mindiff << endl;
  vector<int> result;
  FindSubArrayWithSum(v, 0, totalsum / 2 - mindiff, 0, v.size() / 2, result);
}

