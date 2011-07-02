#include <cstdio>
#include <cstring>
using namespace std;

void Reverse(char *str, int first, int last) {
  if (!str || first < 0 || last < 0) return;
  char *b, *e;
  b = str + first;
  e = str + last;
  while (b < e) {   //Caution!! can't use b++ < e--
    char tmp = *b;
    *b = *e;
    *e = tmp;
    b++; e--;
  }
}

void LeftRotateString(char *str, int i) {
  if (!str || i <= 0 || i >= strlen(str)) return;
  int n = strlen(str);
  Reverse(str, 0, i - 1);
  Reverse(str, i, n - 1);
  Reverse(str, 0, n - 1);
}

int main() {
  char str[200] = {0};
  puts("Please input a string");
  scanf("%s", str);
  puts("Please input an index(< string length)");
  int i;
  scanf("%d", &i);    //Caution!! using &
  LeftRotateString(str, i);
  printf("Left rotated string: %s\n", str);
}
