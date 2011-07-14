#include <iostream>
#include <string>
using namespace std;

void CombinationAux(string &str, int pos, string &result, int num) {
  if (num == 0) {
    cout << result << endl;
    return;
  }
  if (pos == str.size())
    return;
  result.push_back(str[pos++]);
  CombinationAux(str, pos, result, num - 1);
  result.erase(result.end() - 1);
  CombinationAux(str, pos, result, num);
}

void Combination(string &str) {
  string result;
  for (int i = 1; i <= str.size(); ++i) {
    CombinationAux(str, 0, result, i);
  }
}


int main() {
  string str;
  while (cin) {
    cout << endl;
    cout << "Please input a string" << endl;
    cin >> str;
    cout << "------------" << endl;
    Combination(str);
  }
}
