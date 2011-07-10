#include <cstdio>
#include <cstring>
using namespace std;

void CopyOverlappedString(char *src, char *dst) {
  if (!src || !dst) return;
  char *s = dst;
  char *d = dst + (dst - src);
  int len = strlen(dst);
  int i = 0;
  for (; i < len; ++i)
    *d++ = *s++;
  *d = '\0';
  len = dst - src;
  s = src;
  d = dst;
  for (i = 0; i < len; ++i)
    *d++ = *s++;
}


int main() {
  char src[100] = "Hello World!";
  char *dst = &src[13];
  CopyOverlappedString(src, dst);
  puts("Copied string is:");
  puts(dst);
}
