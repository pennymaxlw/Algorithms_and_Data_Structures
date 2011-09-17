#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

void StringTokenize(const string &in, const string &delimiters, list<string> &result) {
  if (in.size() < 2 || delimiters.size() == 0)
    return;
  result.clear();
  unsigned char delim[256] = {0};
  for (int i = 0; i < delimiters.size(); i++) {
    delim[delimiters[i]] = 1;
  }
  int i = 0;
  int cnt = 0;
  int start = 0;
  while (true) {
    while (delim[in[i]] == 1) i++;
    start = i;
    while (i < in.size() && delim[in[i]] == 0) {
      cnt++;
      i++;
    }
    if (cnt > 0) {
      result.push_back(string(in, start, cnt));
    }
    if (i == in.size()) break;
    cnt = 0;
  }
}


int main() {
  string in;
  string delim;
  while (true) {
    cout << "Input string: " << endl;
    getline(cin, in);
    cout << "Input delimiters: " << endl;
    getline(cin, delim);
    list<string> result;
    StringTokenize(in, delim, result);
    cout << "Results: " << endl;
    copy(result.begin(), result.end(), ostream_iterator<string>(cout, "\n"));
  }
}
