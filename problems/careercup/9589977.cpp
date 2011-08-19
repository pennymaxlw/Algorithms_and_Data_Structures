#include <iostream>
using namespace std;

struct SLLNode {
  int val;
  SLLNode *next;
};

class SLList {
public:
  SLList() : head_(NULL) {}
  SLList(int *arr, int len);
  ~SLList();
  void Traversal();
  void SwapAlternateNodes();
  void SwapAlternateNodes2();
private:
  SLList(const SLList&);
  SLList& operator=(const SLList&);  
private:
  SLLNode *head_;
};

SLList::SLList(int *arr, int len) 
  : head_(NULL) {
  if (arr == NULL || len < 1) return;
  head_ = new SLLNode;
  head_->val = arr[0]; head_->next = NULL;
  SLLNode *p = head_;
  for (int i = 1; i < len; ++i) {
    p->next = new SLLNode;
    p = p->next;
    p->val = arr[i];
  }
  p->next = NULL;
}

SLList::~SLList() {
  if (head_ == NULL) return;
  SLLNode *p = head_;
  while (p != NULL) {
    head_ = p;
    p = p->next;
    delete head_;
  }
  head_ = NULL;
}

void SLList::Traversal() {
  if (head_ == NULL) return;
  SLLNode *p = head_;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

void SLList::SwapAlternateNodes() {
  if (head_ == NULL || head_->next == NULL) 
    return;
  SLLNode *p1 = head_, *p2 = NULL, *pp = NULL; 
  while (p1 != NULL && p1->next != NULL) {
    p2 = p1->next;
    p1->next = p2->next;
    p2->next = p1;
    if (pp == NULL)
      head_ = p2;
    else
      pp->next = p2;
    pp = p1;
    p1 = p1->next;
  }
}

void SLList::SwapAlternateNodes2() {
  if (head_ == NULL || head_->next == NULL) 
    return;
  SLLNode *p = head_, *pp = NULL; 
  while (p != NULL && p->next != NULL) {
    cout << p->val << endl;
    if (pp == NULL)
      head_ = p->next;
    else
      pp->next = p->next; 
    p->next = p->next->next;
    pp->next->next = p;
    pp = p;
    p = p->next;
  } 
}

int main() {
  int arr[] = {1,2,3,4,5,6};
  //int arr[] = {1,2,3,4,5};
  //int arr[] = {1,2};
  //int arr[] = {1};
  SLList sll(arr, sizeof(arr) / sizeof (int));
  sll.Traversal();
  sll.SwapAlternateNodes2();
  sll.Traversal();
}
