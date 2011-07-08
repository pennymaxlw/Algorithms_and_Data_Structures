#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;
int cnt = 0;

int GetRecord(string &str, Matrix &record, int i, int j) {
  if (record[i][j] > -1) return record[i][j];
  ++cnt; 
  if (i == j)
    record[i][j] = 1;
  else if (j - i == 1) {
    if (str[i] == str[j]) record[i][j] = 2;
    else record[i][j] = 0;
  } else {
    int k = 0;
    if (str[i] == str[j] &&
        (k = GetRecord(str, record, i+1, j-1)) == j-i-1)
      record[i][j] = k + 2;
    else {
      k = GetRecord(str, record, i+1, j); 
      record[i][j] = max(k, record[i][j-1]);
    }
  }
  return record[i][j];
}

int FindMaxLenPalindrome(string &str) {
  int len = str.size();
  Matrix record(len, vector<int>(len, -1));
  int j = 0;
  while (j < len)
    GetRecord(str, record, 0, j++);
  return record[0][len - 1];
}


int main() {
  while (cin) {
    cout << endl;
    cout << "Please input a string" << endl;
    string s;
    cin >> s;
    cout << "Max Length of parlindrome is " 
      << FindMaxLenPalindrome(s)
      << endl;
    cout << "String length " << s.size() << endl;
    cout << "Cost steps " << cnt << endl;
    cnt = 0;
  }
}
