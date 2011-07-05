#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class SQueue {
public:
  SQueue() {}
  ~SQueue() {}
  T& front() {
    if (stackout_.empty()) {
      while (!stackin_.empty()) {
        stackout_.push(stackin_.top());
        stackin_.pop();
      }
    }
    return stackout_.top();
  }
  T& back() {
    if (stackin_.empty()) {
      while (!stackout_.empty()) {
        stackin_.push(stackout_.top());
        stackout_.pop();
      }
    }
    return stackin_.top();
  }
  size_t size() {
    return stackin_.size() + stackout_.size();
  }
  bool empty() {
    return stackin_.empty() && stackout_.empty();
  }
  void Push(T t) {
    stackin_.push(t);
  }
  void Pop() {
    if (stackout_.empty()) {
      while (!stackin_.empty()) {
        stackout_.push(stackin_.top());
        stackin_.pop();
      }
    }
    if (!stackout_.empty())
      stackout_.pop();
  }
private:
  stack<T> stackin_;
  stack<T> stackout_;
};


int main() {
  SQueue<int> squ;
  squ.Push(1);
  squ.Push(2);
  squ.Push(3);
  squ.Push(4);
  squ.Push(5);
  cout << "back " << squ.back() << " front " << squ.front() << endl;
  squ.Pop();
  squ.Pop();
  squ.Pop();
  cout << "back " << squ.back() << " front " << squ.front() << endl;
  squ.Push(6);
  squ.Push(7);
  cout << "back " << squ.back() << " front " << squ.front() << endl;
}
