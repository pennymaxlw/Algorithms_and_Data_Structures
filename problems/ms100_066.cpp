#include <iostream>
#include <stack>
using namespace std;

void DownTop(stack<int> &sk, int top, int size) {
  int i = 0;
  if (size == 0) {
    //cout << "push top " << top << endl;
    sk.push(top);
  } else {
    i = sk.top();
    sk.pop();
    DownTop(sk, top, --size);
    //cout << "push " << i << endl;
    sk.push(i);
  }
}

void RevertStack(stack<int> &sk) {
  int i = 0;
  int size = sk.size();
  while (size) {
    i = sk.top();
    sk.pop();
    DownTop(sk, i, --size);
    //cout << "current top " << sk.top() << endl;
  }
}


int main() {
  stack<int> sk;
  sk.push(5);
  sk.push(4);
  sk.push(3);
  sk.push(2);
  sk.push(1);
  
  RevertStack(sk);
  while (!sk.empty()) {
    cout << sk.top() << " ";
    sk.pop();
  }
  cout << endl;
}

