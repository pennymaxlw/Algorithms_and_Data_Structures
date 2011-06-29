#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

void RevertWord(char *b, char *e) {
  char tmp;
  while (b < e) {     //Caution: can't use b != e
    tmp = *b;
    *b = *e;
    *e = tmp;
    ++b; 
    --e;
  }
}

void RevertSentence(char *sentence) {
  if (!sentence) return;
  //first revert whole sentence
  RevertWord(sentence, sentence + strlen(sentence) - 1); 
  //then revert each word
  char *p = sentence;
  char *b = NULL;
  while (*p) { 
    while (isspace(*p)) ++p;
    if (*p) 
      b = p;
    else
      break;
    while (*p && !isspace(*p)) ++p;
    if (p)
      RevertWord(b, p - 1);
  }
}

int main() {
  const int MAX = 256;
  char s[MAX];
  puts("Please input a sentence...");
  gets(s);
  printf("Your input sentence is: %s\n", s);
  RevertSentence(s);
  puts("After reverting sentence...");
  printf("%s\n", s);
}
