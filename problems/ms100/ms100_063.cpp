#include <cstdio>
#include <cstring>
using namespace std;

void DeleteCharInStringByDict(char *str, char *dict) {
  if (!str || !dict) return;
  const int MAX = 256;
  char hash[MAX] = {0};
  int len = strlen(str);
  int dictlen = strlen(dict);
  char *p = dict;
  while (*p) hash[*p++] = 1;
  p = str;
  char *save = str;
  while (*p) {
    if (!hash[*p]) *save++ = *p;
    ++p;
  }
  *save = '\0';
}


int main() {
  puts("Please input string");
  const int MAX = 200;
  char str[MAX];
  fgets(str, MAX, stdin);
  puts("Please input dict");
  char dict[MAX];
  fgets(dict, MAX, stdin);
  DeleteCharInStringByDict(str, dict);
  printf("After deleting characters in dict: ");
  puts(str);
}
