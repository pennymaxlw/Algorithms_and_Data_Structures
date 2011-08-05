#include <iostream>
#include <vector>
using namespace std;

template<typename T, int SIZE> 
class Q {
public:
  Q() : data_(SIZE), front_(0), tail_(0) {}
  ~Q() {}
  bool Empty() {
    return (front_ == tail_);
  }
  bool Full() {
    return ((tail_ + 1) % SIZE == front_);
  }
  T* Front() {
    if (Empty()) return NULL;
    return data_[front_];
  }
  bool Push(T t) {
    if (Full())
      return false;
    cout << "Push " << t << endl;
    data_[tail_] = t;
    tail_ = (tail_ + 1) % SIZE;
    return true;
  }
  bool Pop() {
    if (Empty())
      return false;
    cout << "Pop " << data_[front_] << endl;
    front_ = (front_ + 1) % SIZE;
    return true;
  }
private:
  vector<T> data_;
  int front_;
  int tail_;
};


int main() {
  Q<int, 6> q;
  for (int i = 0; i < 5; ++i) {
    if (!q.Push(i + 1)) {
      cout << "ERROR" << endl;
      break;
    }
  }
  //if (!q.Push(6)) cout << "ERROR" << endl;
  if (!q.Pop()) cout << "ERROR" << endl;
  if (!q.Pop()) cout << "ERROR" << endl;
  if (!q.Pop()) cout << "ERROR" << endl;
  if (!q.Pop()) cout << "ERROR" << endl;
  if (!q.Pop()) cout << "ERROR" << endl;
  if (!q.Pop()) cout << "ERROR" << endl;
}
