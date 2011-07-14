#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *sibling;
  Node(int k = 0, Node *n = NULL, Node *s = NULL)
    : val(k), next(n), sibling(s) {}
};

class List {
public:
  List():head_(NULL) {}
  ~List();
  void Insert(int k);
  void Connect(int i, int j);
  List Clone();
  void Traversal();
  Node* head() {return head_;}
  void set_head(Node *p) {head_ = p;}
private:
  Node* Search(int k);
private:
  Node *head_;
};

List::~List() {
  if (!head_) return;
  Node *curr = head_;
  Node *next = NULL;
  while (curr) {
    next = curr->next;
    delete curr;
    curr = next;
  }
  head_ = NULL;
}

void List::Insert(int k) {
  Node *p = new Node(k);
  if (!head_) {
    head_ = p;
    return;
  } else {
    p->next = head_;
    head_ = p;
  }
}

Node* List::Search(int k) {
  if (!head_) return NULL;
  Node *p = head_;
  while (p && p->val != k) p = p->next;
  return p;
}

void List::Connect(int i, int j) {
  Node *p = Search(i);
  Node *q = Search(j);
  if (!p || !q) return;
  p->sibling = q;
}

List List::Clone() {
  if (!head_) return List();
  Node *p = head_;
  Node *q = NULL;
  while (p) {             //create nodes
    q = new Node;
    q->val = p->val;
    q->next = p->sibling;
    q->sibling = p->sibling;
    p->sibling = q;
    p = p->next;
  }
  cout << "22222222222" << endl;
  p = head_;
  while (p) {             //restore new node sibling
    q = p->sibling;
    if (q->sibling)
      q->sibling = q->sibling->sibling;
    p = p->next;
  }
  cout << "333333333333" << endl;
  p = head_;
  Node *newhead = p->sibling;
  q = newhead;
  while (p) {             //split two lists
    q = p->sibling;
    p->sibling = q->next;
    if (p->next)
      q->next = p->next->sibling;
    else
      q->next = NULL;
    p = p->next;
  }
  List newlist;
  newlist.set_head(newhead);
  return newlist;
}

void List::Traversal() {
  if (!head_) return;
  Node *p = head_;
  while (p) {
    cout << p->val;
    if (p->sibling)
      cout << "(" << p->sibling->val << ")";
    cout << " ";
    p = p->next;
  }
  cout << endl;
}


int main() {
  List ls;
  ls.Insert(5);
  ls.Insert(4);
  ls.Insert(3);
  ls.Insert(2);
  ls.Insert(1);
  ls.Connect(1, 3);
  ls.Connect(2, 5);
  ls.Connect(4, 2);
  
  ls.Traversal();
  
  List newls = ls.Clone();
  ls.Traversal();
}
