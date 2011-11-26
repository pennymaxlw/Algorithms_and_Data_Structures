#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int d, Node *p = NULL)
    : data(d), next(p) {}
};

class List {
public:
  List()
    : head_(NULL) {}
  ~List();
  void Prepend(int k);
  void Reverse(int m);
  void Traverse();
private:
  Node* ReverseAux(Node *p, int m);
private:
  Node *head_;
};

List::~List() {
  if (head_ == NULL)
    return;
  Node *p = head_;
  while (p != NULL) {
    Node *q = p->next;
    delete p;
    p = q;
  }
  head_ = NULL;
}

void List::Prepend(int k) {
  Node *p = new Node(k);
  if (head_ != NULL)
    p->next = head_;
  head_ = p;
}

void List::Reverse(int m) {
  if (m < 1 || head_ == NULL)
    return;
  head_ = ReverseAux(head_, m);
}

Node* List::ReverseAux(Node *p, int m) {
  if (p == NULL)
    return NULL;
  Node *pre = NULL, *cur = p, *next = NULL;
  int i = m;
  while (cur != NULL && i--) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  p->next = ReverseAux(cur, m);
  return pre;
}

void List::Traverse() {
  if (head_ == NULL)
    return;
  Node *p = head_;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int main() {
  List l;
  for (int i = 9; i > 0; i--)
    l.Prepend(i);
  l.Traverse();
  l.Reverse(3);
  l.Traverse();
}
