#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

bool CheckPopArray(vector<int> &push_v, vector<int> &pop_v) {
  if (push_v.empty() || 
      pop_v.empty() || 
      push_v.size() != pop_v.size()) 
    return false;
  stack<int> stack;
  vector<int>::iterator itpush = push_v.begin();
  vector<int>::iterator itpop = pop_v.begin();
  while (itpush != push_v.end() && itpop != pop_v.end()) {
    if (!stack.empty() && *itpop == stack.top()) {
      cout << "pop " << *itpop;
      stack.pop();
      ++itpop;
      cout << " now itpop " << *itpop << endl;
    } else {
      if (*itpush != *itpop) {
        cout << "push " << *itpush;
        stack.push(*itpush);
        ++itpush;
        cout << " now itpush " << *itpush << endl;
      } else {
        ++itpush;
        ++itpop;
        cout << "++itpop, ++itpush " << *itpop << " " << *itpush << endl; 
      } 
    }    
  }
  cout << "---now itpop " << *itpop << endl;
  while (itpop != pop_v.end() && !stack.empty() &&
      *itpop == stack.top()) {
    stack.pop();
    ++itpop;
    cout << "==now itpop " << *itpop << endl;
  }
  if (itpush == push_v.end() && itpop == pop_v.end())
    return true;
  else
    return false;
}

int main() {
  int push_arr[] = {1,2,3,4,5};
  int pop_arr[] = {4,5,3,2,1}; //Yes
  //int pop_arr[] = {4,3,5,1,2}; //No
  //int push_arr[] = {1,2,3,4,5,6,7,8,9,10};
  //int pop_arr[] = {5,4,3,7,6,2,1,8,9,10}; //Yes
  vector<int> push_v(push_arr, push_arr + sizeof(push_arr)/sizeof(int));
  vector<int> pop_v(pop_arr, pop_arr + sizeof(pop_arr)/sizeof(int));
  cout << "push array:" << endl;;
  copy(push_v.begin(), push_v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "pop array:" << endl;
  copy(pop_v.begin(), pop_v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  bool flag = CheckPopArray(push_v, pop_v);
  if (flag)
    cout << "YES...The pop array is the right one for the push array!!" << endl;
  else
    cout << "NO...The pop array is NOT the right one for the push array!!" << endl;
} 
