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

void CopyOverlappedString2(const char *src, char *dst) {
  if (!src || !dst || src == dst) return;
  const char *psrc = NULL;
  char *pdst = NULL;
  int len = strlen(src);
  if (src < dst && dst < src + len) {
    psrc = src + len;
    pdst = dst + len;
    for (int i = len; i >= 0; --i)
      *pdst-- = *psrc--;
  } else {
    psrc = src;
    pdst = dst;
    while ((*pdst++ = *psrc++) != '\0');
    *pdst = '\0';
  }
}


int main() {
  char src[100] = "Hello World!";
  //char *dst = &src[1];
  char dst[100];
  CopyOverlappedString2(src, dst);
  puts("Copied string is:");
  puts(dst);
}
