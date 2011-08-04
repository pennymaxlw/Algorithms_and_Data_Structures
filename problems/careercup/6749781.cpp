#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void Encoding(char* d, const char *s) {
  if (s == NULL || d == NULL)
    return;
  int len = strlen(s);
  if (len < 2)
    return;
  int i = 0, save = 0;
  int count = 1;
  d[0] = s[0];
  for (int i = 1; i < len; ++i) {
    if (s[i] == d[save]) {
      ++count;
    } else {
      if (count == 1) {
        d[++save] = s[i];
      } else {
        d[save + 2] = s[i];
        d[save + 1] = d[save];
        d[save] = '0' + count;
        save += 2;
        count = 1;
      }
    }
  }
  if (count > 1) {
    d[save + 1] = d[save];
    d[save] = '0' + count;
    save += 2;
  } else
    ++save;
  d[save] = '\0';
}

void Decoding(char *d, const char *s) {
  if (s == NULL || d == NULL)
    return;
  int len = strlen(s);
  if (len < 2)
    return;
  int i = 0, save = 0;
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i + 1 < len && isdigit(s[i]) && isalpha(s[i + 1])) {
      count = s[i] - '0';
      while (count-- > 0)
        d[save++] = s[i + 1];
      ++i;
    } else {
      d[save++] = s[i];
    }
  }
  d[save] = '\0';
}


int main() {
  char s[100];
  char d[100];
  while (cin) {
    cout << endl;
    cout << "Input a string" << endl;
    cin >> s;
    cout << "Encoded string" << endl;
    Encoding(d, s);
    cout << d << endl;
    cout << "Decoding string" << endl;
    Decoding(s, d);
    cout << s << endl;
  }
}
