#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int NextPalindromeNum(int n) {
  stringstream ss;
  ss << n;
  string s = ss.str();
  int len = s.size();
  string s1, s2;
  if ((len & 1) == 0) { //even
    s1 = s.substr(0, len / 2);
    s2 = s.substr(len / 2, len / 2);
    //cout << s1 << endl;
    //cout << s2 << endl;
    if (s1 > s2) {
      s = s1;
      reverse(s1.begin(), s1.end());
      s += s1;
    } else {
      int tmp = atoi(s1.c_str()) + 1;
      ss.str("");
      ss << tmp;
      s1 = ss.str();
      cout << "s1 " << s1 << endl;
      s = s1;
      reverse(s1.begin(), s1.end());
      s += s1;
    }
  } else { //odd
    
  }
  return atoi(s.c_str());
}


int main() {
  int n = 0;
  while (cin) {
    cout << endl;
    cout << "Input a number" << endl;
    cin >> n;
    n = NextPalindromeNum(n);
    cout << "Next palindrome" << endl;
    cout << n << endl;
  }
}
