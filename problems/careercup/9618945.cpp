#include <iostream>
#include <string>
using namespace std;

void PrintContinuousChars(const string & s) {
  if (s.size() < 1) return;
  char pre = s[0];
  int diff = 0, prediff = 0;
  bool linestart = true;
  cout << s[0];
  for (int i = 1; i < s.size(); ++i) {
    diff = s[i] - pre;
    if ((diff != 1 && diff != -1) || 
        (!linestart && diff != prediff)) {
      cout << endl;
      linestart = true;
    } else
      linestart = false;
    prediff = diff;
    pre = s[i];
    cout << s[i];
  }
  cout << endl;
}

void PrintContinuousChars2(const string & s) {
  if (s.size() < 1)
    return;
  int i = 0;
  cout << s[i++];
  while (i <= s.size()) {
    if (s[i] - s[i-1] != 1)
      cout << endl;
    cout << s[i++];
  }
}

int main() {
  string s;
  while (cin) {
    cin >> s;
    cout << "==========" << endl;
    PrintContinuousChars2(s);
  }
}
