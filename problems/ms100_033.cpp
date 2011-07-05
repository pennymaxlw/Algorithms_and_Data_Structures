#include <cstdio>
#include <cstring>
using namespace std;

void PrintRangeChar(const char *front, const char *rear) {
  if (!front || !rear) return;
  const char *p = front;
  while (p <= rear) putchar(*p++);
}

void FindSubstringWithDict(const char *str, int len, 
                          const char *dict, int lendict) {
  const int MAX = 256;
  char count[MAX];
  int i = 0;
  for (; i < MAX; ++i) {
    count[i] = -1;
  }
  for (i = 0; i < lendict; ++i) {
    count[dict[i]] = 0;
  }
  int dictsum = 0;
  const char *front = str, *rear = str;
  while (*rear) {
    if (count[*rear] == 0) ++dictsum;
    if (count[*rear] >= 0) ++count[*rear];
    if (dictsum == lendict) {
      while (front < rear) {
        if (count[*front] > 0)
          --count[*front];
        if (count[*front] == 0) {
          printf("Found substring: ");
          PrintRangeChar(front, rear);
          printf("\n");
          --dictsum; 
        }
        ++front;
        if (dictsum < lendict)
          break;
      }
    }
    ++rear;
  } 
}


int main() {
  char str[200];
  char dict[200];
  puts("Please input string");
  gets(str);
  puts("Please input dict");
  gets(dict);
  FindSubstringWithDict(str, strlen(str), dict, strlen(dict));
}
