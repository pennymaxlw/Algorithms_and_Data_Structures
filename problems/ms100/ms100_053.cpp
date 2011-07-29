#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int cnt = 0;

void PermutationRecursive(string &s, int first = 0) {
  if (first == s.size() - 1) {
    cout << s << endl;
    ++cnt;
    return;
  }
  for (int i = first; i < s.size(); ++i) {
    swap(s[first], s[i]);
    PermutationRecursive(s, first + 1);
    swap(s[first], s[i]);
  }
}

void PermutationRecursive2(set<char> &chars, vector<char> &result) {
  if (chars.empty()) {
    for(int i = 0; i < result.size(); ++i)
      cout << result[i];
    cout << endl;
    return;
  }
  set<char>::iterator it = chars.begin();
  for (; it != chars.end(); ++it) {
    chars.erase(*it);
    result.push_back(*it);
    PermutationRecursive2(chars, result);
    result.pop_back();
    chars.insert(*it);
  }
}

void PermutationSort(string &s) {
  if (s.size() <= 1) {
    cout << s << endl;
    ++cnt;
    return;
  }
  sort(s.begin(), s.end());
  cout << s << endl;
  ++cnt;
  int i, j;
  int sz = s.size();
  while (1) {
    for (i = sz - 2; i >= 0; --i) {
      if (s[i] < s[i + 1])
        break;
    } 
    if (i < 0) break;
    for (j = sz - 1; j > i; --j) {
      if (s[j] > s[i])
        break;
    }
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    cout << s << endl;
    ++cnt;
  }
}


int main() {
  while (cin) {
    cout << endl;
    cout << "Please input a string" << endl;
    string s;
    cin >> s;
    cout << "Permutations" << endl;
    //PermutationRecursive(s);
    vector<char> result;
    set<char> chars(s.begin(), s.end());
    PermutationRecursive2(chars, result);
    //PermutationSort(s);
    cout << "Total: " << cnt << endl;
    cnt = 0;
  }
}
