#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void FindValidParens(int lpar, int rpar, vector<char> &result) {
  if (lpar < 0 || rpar < 0) return;
  if (lpar == 0 && rpar == 0) {
    for (int i = 0; i < result.size(); ++i)
      cout << result[i];
    cout << endl;
    return;
  }
  if (lpar > 0) {
    result.push_back('(');
    FindValidParens(lpar - 1, rpar, result);
    result.pop_back();
  }
  if (lpar < rpar) {
    result.push_back(')');
    FindValidParens(lpar, rpar - 1, result);
    result.pop_back();
  }
}


int main() {
  int count = 0;
  while (cin >> count) {
    vector<char> result(count);
    FindValidParens(count, count, result);
    cout << endl;
  }
}
