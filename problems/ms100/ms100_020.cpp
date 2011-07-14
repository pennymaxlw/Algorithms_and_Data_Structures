#include <cstdio>
#include <cctype>
using namespace std;

int StrToInt(const char *str) {
  if (!str) return 0;
  int sign = 1;
  const char *p = str;
  while (isspace(*p)) ++p;
  if (*p == '-') sign = -1;
  if (*p == '+' || *p == '-') ++p;
  int val = 0;
  while (isdigit(*p)) {
    val = val * 10 + (*p - '0');  
    ++p;
  }
  if (*p != '\0') return 0;
  return val * sign;
}

int main() {
  puts("Please input a number string.");
  char str[200];
  gets(str);
  printf("Number is %d\n", StrToInt(str));
}
