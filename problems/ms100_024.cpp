#include <iostream>
using namespace std;

struct SLNode {
  int val;
  SLNode *next;
  SLNode(int i = 0, SLNode *p = NULL)
    : val(i), next(NULL) {}
};

class SList {
friend SList MergeTwoListsIterative(SList &ls1, SList &ls2);
friend SList MergeTwoListsRecursive(SList &ls1, SList &ls2);
public:
  SList() : head_(NULL) {}
  ~SList();
  void Insert(int i);
  void Traversal();
  void ReverseIterative();
  void ReverseRecursive();
  void MergeIterative(SList &ls);
private:
  SLNode* ReverseRecursiveAux(SLNode *p);
  SLNode* ReverseRecursiveAux2(SLNode *p);
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

void SList::ReverseIterative() {
  if (!head_ || !head_->next) return;
  SLNode *prev = NULL,
         *curr = head_,
         *next = NULL;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head_ = prev;
}

void SList::ReverseRecursive() {
  if (!head_ || !head_->next) return;
  ReverseRecursiveAux2(head_);
}

SLNode* SList::ReverseRecursiveAux(SLNode *p) {
  if (p->next) {
    SLNode* pp = ReverseRecursiveAux(p->next);
    pp->next = p;
    p->next = NULL;
  } else {
    head_ = p;
  }
  return p;
}

SLNode* SList::ReverseRecursiveAux2(SLNode *p) {
  if(p) {
    SLNode *pp = ReverseRecursiveAux(p->next);
    if (!pp) head_ = p;
    pp->next = p;
    p->next = NULL;
  } 
  return p;
}

void SList::MergeIterative(SList &ls) {
  if (!ls.head_) return;
  if (!head_) {
    head_ = ls.head_;
    ls.head_ = NULL;
    return;
  }
  SLNode *p = head_;
  SLNode *q = ls.head_;
  SLNode *pp = NULL;
  SLNode *qq = NULL;
  while (p && q) {
    if (p->val < q->val) {
      while (p && p->val < q->val) {
        pp = p;
        p = p->next;
      }
      pp->next = q;
      //cout << "connected " << pp->val << " " << q->val << endl;
    } else {
      while (q && q->val < p->val) {
        qq = q;
        q = q->next;
      }
      qq->next = p;
      //cout << "connected " << qq->val << " " << p->val << endl;
    }
  }
  if (head_->val > ls.head_->val)
    head_ = ls.head_;
  ls.head_ = NULL;
}

SList MergeTwoListsIterative(SList &ls1, SList &ls2) {
  SList result;
  SLNode *head = NULL;
  SLNode *head1 = ls1.head_;
  SLNode *head2 = ls2.head_;
  if (!head1 && !head2) return result;
  if (!head1) {
    result.head_ = head2; 
    return result;
  }
  if (!head2) {
    result.head_ = head1;
    return result;
  }
  if (head1->val < head2->val) {
    head = head1;
    head1 = head1->next;
  } else {
    head = head2;
    head2 = head2->next;
  }
  SLNode *p = head;
  while (head1 && head2) {
    if (head1->val < head2->val) {
      p->next = head1;
      p = head1;
      head1 = head1->next;
    } else {
      p->next = head2;
      p = head2;
      head2 = head2->next;
    }
  }
  if (head1)
    p->next = head1;
  if (head2)
    p->next = head2;
  result.head_ = head;
  ls1.head_ = ls2.head_ = NULL;
  return result;
}

SLNode* MergeTwoListsRecursiveAux(SLNode *head1, SLNode *head2) {
  if (!head1) return head2;
  if (!head2) return head1;
  SLNode* head = NULL;
  if (head1->val < head2->val) {
    head = head1;
    head->next = MergeTwoListsRecursiveAux(head1->next, head2);
  } else {
    head = head2;
    head->next = MergeTwoListsRecursiveAux(head1, head2->next);
  }
  return head;
}


SList MergeTwoListsRecursive(SList &ls1, SList &ls2) {
  SList result;
  SLNode *head1 = ls1.head_;
  SLNode *head2 = ls2.head_;
  if (!head1 && !head2) return result;
  if (!head1) {
    result.head_ = head2; 
    return result;
  }
  if (!head2) {
    result.head_ = head1;
    return result;
  }
  result.head_ = MergeTwoListsRecursiveAux(head1, head2);
  ls1.head_ = ls2.head_ = NULL;
  return result;
}

int main() {
  SList ls;
  ls.Insert(8);
  ls.Insert(5);
  ls.Insert(4);
  ls.Insert(1);

  SList ls2;
  ls2.Insert(10);
  ls2.Insert(9);
  ls2.Insert(6);
  ls2.Insert(3);
  ls2.Insert(2);

  ls.Traversal();
  ls2.Traversal();
  //SList result = MergeTwoListsIterative(ls2, ls);
  SList result = MergeTwoListsRecursive(ls2, ls);
  result.Traversal();
  //ls2.MergeIterative(ls);
  //ls2.Traversal();
  //ls.ReverseIterative();
  //ls.Traversal();
  //ls.ReverseRecursive();
  //ls.Traversal();
}
