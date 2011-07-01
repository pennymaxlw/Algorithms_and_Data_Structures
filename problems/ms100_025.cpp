#include <iostream>
#include <cctype>
using namespace std;

int FindMaxLengthDigits(char *output, char *input) {
  if (!output || !input) return; //Caution!! 
  char *p = input;
  int max = 0;
  char *maxb = NULL;
  int i = 0;
  char *b = NULL;
  bool inside = false;
  while (*p) {
    if (isdigit(*p)) {
      if (!inside) {
        b = p;
        inside = true;
        i = 0;
      }
      ++i;
    } else {
      if (inside) {
        inside = false;
        if (i > max) {
          max = i;
          maxb = b;
        }
      }
    }
    ++p;
  }
  if (i > max) {    //Caution!! need checking after one pass
    max = i;
    maxb = b;
  }

  p = maxb;
  while (p < maxb + i) {
    *output++ = *p++;
  }
  *output = '\0';
  return max;
}


int main() {
  char in[] = "abcd12345ed125ss123456789";
  char out[100];
  int max = FindMaxLengthDigits(out, in);
  cout << "Max digit length " << max << endl;
  cout << out << endl;
}
