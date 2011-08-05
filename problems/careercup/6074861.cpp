#include <cstring> 
#include <cstdio>
using namespace std;

char* FindReplace(char* src, char* find, char* replace) {
  if (src == NULL || find == NULL || replace == NULL)
    return NULL;
  int srclen = strlen(src);
  int findlen = strlen(find);
  int replen = strlen(replace);
  if (findlen == 0 || replen == 0)
    return src;
  int maxlen = (findlen > replen ? findlen : replen);
  int retlen = (srclen / findlen + 1) * maxlen;
  char *ret = new char[retlen + 1];
  char *psrc = src;
  char *ppre = src;
  char *pret = ret;
  int cnt = 0;
  while (*psrc && (psrc = strstr(psrc, find)) != NULL) {
    while (ppre < psrc) *pret++ = *ppre++;
    while (cnt < replen) *pret++ = *(replace + cnt++); 
    psrc += findlen;
    ppre = psrc;
    cnt = 0;
  }
  while (*ppre) *pret++ = *ppre++;
  *pret = '\0';
  return ret;
}


int main() {
  char src[100];
  char find[100];
  char replace[100];
  char *ret = NULL;
  while (1) {
    puts("\n\nInput source find replace");
    scanf("%s", src);
    scanf("%s", find);
    scanf("%s", replace);
    ret = FindReplace(src, find, replace);
    printf("Replaced string:\n%s", ret);
    delete ret;
    ret = NULL;
  }
}
