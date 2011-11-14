#include <iostream>
#include <cctype>
using namespace std;

struct Node {
  char data;
  Node *next;
  Node(char d = 0, Node *p = NULL)
    : data(d), next(p) {}
};

class List {
public:  
  List();
  ~List();
  void Prepend(char key);
  void Traversal();
  void Arrange();
  void Arrange2();
private:
  Node *head_;
};

List::List()
  : head_(NULL) {}

List::~List() {
  if (head_ == NULL)
    return;
  Node *p = head_, *tmp = NULL;
  while (p != NULL) {
    tmp = p->next;
    delete p;
    p = tmp;
  }
  head_ = NULL;
}

void List::Prepend(char key) {
  Node *p = new Node(key, NULL);
  p->next = head_;
  head_ = p;
}

void List::Traversal() {
  if (head_ == NULL)
    return;
  Node *p = head_;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

void List::Arrange() {
  if (head_ == NULL)
    return;
  Node *pd = head_, *pa = head_, *ppa = NULL;
  while (pd != NULL && isalpha(pd->data))
    pd = pd->next;
  if (pd != NULL)
    head_ = pd;
  while (pd != NULL && pa != NULL) {
    while (pd != NULL && isalpha(pd->data))
      pd = pd->next;
    while (pa != NULL && isdigit(pa->data)) {
      ppa = pa;
      pa = pa->next;
    }
    if (pd == NULL || pa == NULL)
      break;
    Node *tmp = pa->next;
    if (ppa != NULL)
      ppa->next = tmp;
    pa->next = pd->next;
    pd->next = pa;
    pd = pa->next;
    pa = tmp;
  }
}

void List::Arrange2() {
  if (head_ == NULL)
    return;
  // Divide list to two seperated list: one with digits, one with alpha
  Node *ahead = NULL, *dhead = NULL;
  Node *pa = NULL, *pd = NULL, *p = head_;
  while (p != NULL) {
    if (isdigit(p->data)) {
      if (dhead == NULL) {
        dhead = p;
        pd = p;
      } else {
        pd->next = p;
        pd = p;
      }
    }
    if (isalpha(p->data)) {
      if (ahead == NULL) {
        ahead = p;
        pa = p;
      } else {
        pa->next = p;
        pa = p;
      }
    }
    p = p->next;
  }
  pa->next = pd->next = NULL;
 
  // Assemble to target list
  head_ = dhead;
  pa = ahead;
  pd = dhead;
  while (pa != NULL && pd != NULL) {
    Node *tmp = pa->next;
    pa->next = pd->next;
    pd->next = pa;
    pa = tmp;
    pd = pd->next->next;
  }
  // append leave nodes
  if (pa != NULL) {
    pd = head_;
    while (pd->next != NULL)
      pd = pd->next;
    pd->next = pa;
  }
}


int main() {
  List l;
  //l.Prepend('4');
  //l.Prepend('3');
  //l.Prepend('2');
  //l.Prepend('1');
  //l.Prepend('d');
  //l.Prepend('c');
  //l.Prepend('b');
  //l.Prepend('a');
  l.Prepend('g');
  l.Prepend('f');
  l.Prepend('e');
  l.Prepend('6');
  l.Prepend('5');
  l.Prepend('d');
  l.Prepend('c');
  l.Prepend('b');
  l.Prepend('a');
  l.Prepend('4');
  l.Prepend('3');
  l.Prepend('2');
  l.Prepend('1');
  cout << "Before:" << endl;
  l.Traversal();
  l.Arrange2();
  cout << "After:" << endl;
  l.Traversal();
}
