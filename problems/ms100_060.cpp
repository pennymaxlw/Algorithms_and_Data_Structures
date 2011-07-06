#include <iostream>
using namespace std;

struct SLNode {
  int val;
  SLNode *next;
  SLNode(int i = 0, SLNode *p = NULL)
    : val(i), next(NULL) {}
};

class SList {
public:
  SList() : head_(NULL) {}
  ~SList();
  SLNode* Insert(int i);
  void Traversal();
  void DeleteNode(SLNode *pDeleted);
private:
private:
  SLNode *head_;
};

SList::~SList() {
  if (!head_) return;
  SLNode *p = head_;
  SLNode *tmp = NULL;
  while (p) {
    tmp = p->next;
    delete p;
    p = tmp;
  }
  head_ = NULL;
}

SLNode* SList::Insert(int i) {
  SLNode *p = new SLNode(i);
  if (head_) {
    p->next = head_;
  }
  head_ = p;
  return p;
}

void SList::Traversal() {
  if (!head_) return;
  SLNode *p = head_;
  while (p) {
    cout << p->val << " ";
    p = p->next; 
  }
  cout << endl;
}

void SList::DeleteNode(SLNode *pDeleted) {
  if (!pDeleted || !head_) return;
  SLNode *p = pDeleted->next;
  if (p) {
    pDeleted->val = p->val;
    pDeleted->next = p->next; 
  } else { // this is tail node
    SLNode *pp = NULL;
    p = head_;
    while (p->next) {
      pp = p;
      p = p->next;
    }
    pp->next = NULL;
    delete p;
  }
}

int main() {
  SList ls;
  SLNode *p = NULL;
  ls.Insert(8);
  ls.Insert(5);
  ls.Insert(4);
  ls.Insert(1);
  ls.Insert(3);
  p = ls.Insert(6);

  ls.Traversal();
  ls.DeleteNode(p);
  ls.Traversal();
}
