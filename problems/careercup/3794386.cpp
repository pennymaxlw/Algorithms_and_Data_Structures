#include <iostream>
#include <stack>
using namespace std;

void PutElem(stack<int> &s, int k) {
  if (s.empty()) {
    s.push(k);
  } else {
    int t = s.top();
    if (k < t)
      s.push(k);
    else {
      s.pop();
      PutElem(s, k);
      s.push(t);
    }
  }
}

void SortStack(stack<int> &s) {
  if (!s.empty()) {
    int t = s.top();
    s.pop();
    SortStack(s);
    PutElem(s, t);
  }
}


int main() {
  stack<int> s;
  s.push(3);
  s.push(1);
  s.push(4);
  s.push(6);
  s.push(5);
  s.push(2);

  SortStack(s);
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}
