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
  void Insert(int i);
  void Traversal();
  void ReverseTraversal();
private:
  void ReverseTraversalAux(SLNode* node);
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

void SList::Insert(int i) {
  SLNode *p = new SLNode(i);
  if (head_) {
    p->next = head_;
  }
  head_ = p;
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

void SList::ReverseTraversal() {
  if (!head_) return;
  ReverseTraversalAux(head_);
  cout << endl;
}

void SList::ReverseTraversalAux(SLNode* node) {
  if (node) {
    ReverseTraversalAux(node->next);
    cout << node->val << " ";
  }
}

int main() {
  SList ls;
  ls.Insert(8);
  ls.Insert(5);
  ls.Insert(4);
  ls.Insert(1);

  ls.Traversal();
  ls.ReverseTraversal();
}
