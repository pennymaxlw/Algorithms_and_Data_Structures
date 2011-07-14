#include <cstdio>
using namespace std;

char FindFirstSingleChar(char *str) {
  const int MAX = 256;
  unsigned int dict[MAX] = {0};
  char *p = str;
  while (*p) {
    ++dict[*p];
    ++p;
  }
  p = str;
  while (*p) {
    if (dict[*p] == 1) 
      return *p;  
    ++p;
  }
}

int main() {
  puts("Please input a string");
  char in[200];
  gets(in);
  char c = FindFirstSingleChar(in);
  printf("First single char: %c", c);
}
