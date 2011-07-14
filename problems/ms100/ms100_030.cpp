#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int Count1InDec(int n) {
  if (n < 1) return 0;
  if (n < 10) return 1;
  vector<int> v;
  v.push_back(1);
  int base = 10;
  int m = n / 10;
  while (m >= 10) {
    v.push_back(10 * v.back() + base);
    base = base * 10; 
    m = m / 10;
  }
  //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  //cout << endl;
  //cout << "base " << base << endl;
  int count = 0;
  int d = 0;
  while (n >= 10) {
    d = n / base;
    n = n % base;  
    //cout << "d " << d << " n " << n << endl;
    if (d > 1) {
      count += v.back() * d + base;
    } else if (d == 1) {
      count += v.back() + n + 1; 
    }
    d = n;
    base = base / 10;
    v.pop_back();
  }
  if (n > 0) ++count;
  return count;
}

int Count1InDecBruteForce(int n) {
  if (n < 1) return 0;
  int i = 1;
  int count = 0;
  int v = 0;
  int r = 0;
  while (i <= n) {
    v = i;
    while (v) {
      r = v % 10;
      if (r == 1) ++count;
      v = v / 10;
    } 
    ++i;
  }
  return count;
}

int main() {
  cout << "Please input n" << endl;
  int n = 0;
  cin >> n;
  cout << "Result(Math): " << Count1InDec(n) << endl;
  cout << "Result(Brute-force): " << Count1InDecBruteForce(n) << endl;
}
