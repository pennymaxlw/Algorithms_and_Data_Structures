#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

void ThreeWayPartition(char *s) {
  if (s == NULL) return;
  int len = strlen(s);
  if (len < 3) return;
  char *b = s;
  char *e = s + len - 1;
  char *mid = s;
  while (mid <= e) {
    if (isupper(*mid))
      swap(*b++, *mid++);
    else if (isdigit(*mid))
      swap(*e--, *mid);
    else
      ++mid;
  }
}


int main() {
  char s[100];
  while (cin) {
    cout << endl;
    cout << "Input a string" << endl;
    cin >> s;
    cout << "Three Ways Partition" << endl;
    ThreeWayPartition(s);
    cout << s << endl;
  }
}
