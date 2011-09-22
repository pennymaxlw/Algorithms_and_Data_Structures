#include <iostream>
using namespace std;

int MatchHere(char*, char*);
int MatchHere2(char*, char*);

int MatchStar(int c, char *regexp, char *text) {
  do {
    if (MatchHere(regexp, text))
      return 1;
  } while (*text != '\0' && (*text++ == c || c == '.'));  
  return 0;
}

int MatchHere(char *regexp, char *text) {
  if (regexp[0] == '\0') 
    return 1;
  if (regexp[1] == '*')
    return MatchStar(regexp[0], regexp + 2, text);
  if (regexp[0] == '$' && regexp[1] == '\0')
    return *text == '\0';
  if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
    return MatchHere(regexp + 1, text + 1);
  return 0;
}

int MatchStar2(char *regexp, char *text) {
  do {
    if (MatchHere2(regexp, text))
      return 1;
  } while (*text++ != '\0');  
  return 0;
}

int MatchHere2(char *regexp, char *text) {
  if (regexp[0] == '\0') 
    return 1;
  if (regexp[0] == '*')
    return MatchStar2(regexp + 1, text);
  if (regexp[0] == '$' && regexp[1] == '\0')
    return *text == '\0';
  if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
    return MatchHere2(regexp + 1, text + 1);
  return 0;
}

int Match(char *regexp, char *text) {
  if (regexp[0] == '^')
    return MatchHere2(regexp + 1, text);
  do {
    if (MatchHere2(regexp, text))
      return 1;
  } while (*text++ != '\0');
  return 0;
}

int main() {
  char text[100] = {0};
  char regexp[100] = {0};
  while (true) {
    cout << "Input text:" << endl;
    cin >> text;
    cout << "Input regexp:" << endl;
    cin >> regexp;
    cout << text << endl;
    cout << regexp << endl;
    if (Match(regexp, text))
      cout << "YES!!" << endl;
    else
      cout << "NO!!" << endl;
  }
}
