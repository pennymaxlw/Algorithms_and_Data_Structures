#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void PrintAnagramSubstring(const string &stn, const string &anagram) {
  size_t stnsize = stn.size();
  size_t agmsize = anagram.size();
  if (stnsize < 1 || agmsize < 1 || stnsize < agmsize)
    return;
  int hash[256] = {0};
  int count = 0;
  for (int i = 0; i < agmsize; i++) {
    if (hash[anagram[i]] == 0)
      count++;
    hash[anagram[i]]++;
  }
  int i = 0, j = 0;
  int tmpcount = 0;
  int tmphash[256] = {0};
  int idx = 0;
  while (j < stnsize) {
    idx = stn[j];
    if (hash[idx] == 0) {
      tmpcount = 0;
      j++;
      i = j;
      fill(tmphash, tmphash + 256, 0);
    } else {
      tmphash[idx]++;
      if (tmphash[idx] == hash[idx]) {
        tmpcount++;
        if (tmpcount == count) {
          while (i < j) {
            idx = stn[i];
            tmphash[idx]--;
            if (tmphash[idx] < hash[idx]) {
              tmpcount--;
              break;            
            }
            i++;
          }
          if (j - i + 1 == agmsize) {
            cout << "Found: " << endl;
            for (int k = i; k <= j; k++)
              cout << stn[k];
            cout << endl;
          }
        }
      }
      j++;
    }
  }
}


int main() {
  string stn, anagram;
  while (cin) {
    cout << endl;
    cout << "Input sentence:" << endl;
    getline(cin, stn);
    cout << "Input anagram:" << endl;
    getline(cin, anagram);
    PrintAnagramSubstring(stn, anagram); 
  }
}
