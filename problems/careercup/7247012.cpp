#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct SLLNode {
  int val;
  SLLNode *next;
  SLLNode(int v, SLLNode *p = NULL)
    : val(v), next(p) {}
};

class SLList {
public:
  SLList() : head_(NULL) {}
  SLList(int *arr, int len) : head_(NULL) {
    FromArray(arr, len);
  }
  ~SLList() {Clear();}
  void Insert(int v);
  void Traverse();
  void DelDupSorted();
  void DelDupUnsorted();
private:
  void FromArray(int *arr, int len);
  void Clear();
private:
  SLLNode *head_;
};

void SLList::FromArray(int *arr, int len) {
  if (arr == NULL || len < 1) return;
  SLLNode *p = NULL, *pp = NULL;
  for (int i = 0; i < len; ++i) {
    p = new SLLNode(arr[i]);
    if (head_ == NULL) { 
      head_ = p;
      pp = p;
    } else {
      pp->next = p;
      pp = p;
    }
  }
}

void SLList::Clear() {
  SLLNode *p = head_, *tmp = NULL;
  while (p != NULL) {
    tmp = p;
    p = p->next;
    delete tmp;
  }
  head_ = NULL;
}

void SLList::Insert(int v) {
  SLLNode *p = new SLLNode(v);
  p->next = head_;
  head_ = p;
}

void SLList::Traverse() {
  if (head_ == NULL) return;
  SLLNode *p = head_;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

void SLList::DelDupSorted() {
  if (head_ == NULL || head_->next == NULL) 
    return;
  SLLNode *curr = head_->next, *pre = head_;
  SLLNode *tmp = NULL;
  while (curr != NULL) {
    if (curr->val == pre->val) {
      tmp = curr->next;
      delete curr;
      curr = tmp;
      pre->next = curr;
    } else {
      pre = curr;
      curr = curr->next;
    }
  }
}

void SLList::DelDupUnsorted() {
  if (head_ == NULL || head_->next == NULL)
    return;
  SLLNode *curr = head_->next, *pre = head_;
  SLLNode *tmp = NULL;
  set<int> nodeset;
  nodeset.insert(head_->val);
  while (curr != NULL) {
    if (nodeset.count(curr->val) > 0) {
      tmp = curr->next;
      delete curr;
      curr = tmp;
      pre->next = curr;
    } else {
      nodeset.insert(curr->val);
      pre = curr;
      curr = curr->next;
    }
  }
}

int main() {
  int arr[] = {1,1,1,2,3,4,4,4,4,5,6,7,8,9,9,9};
  random_shuffle(arr, arr + sizeof(arr) / sizeof(int));
  SLList l(arr, sizeof(arr) / sizeof(int));
  l.Traverse();
  l.DelDupUnsorted();
  l.Traverse();
}
