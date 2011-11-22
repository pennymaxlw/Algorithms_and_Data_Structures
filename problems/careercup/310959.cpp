#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d = 0, Node *l = NULL, Node *r = NULL)
    : data(d), left(l), right(r) {}
};

class BTree {
public:
  BTree() : head_(NULL) {}
  BTree(int *p, int len);
  ~BTree();
  void Insert(int k);
  Node* ConnectLeafs(bool FLR = true); // FLR: flag of from left to right or inverse
private:
  void Clear(Node *p);
  void ConnectLeafsAux(Node *p, Node *&pp, bool FLR, Node *&head);
  Node* CreateFromArray(int *p, int b, int e);
private:
  Node *head_;
};

BTree::BTree(int *p, int len)
  : head_(NULL) {
  if (p == NULL || len < 1)
    return;
  head_ = CreateFromArray(p, 0, len - 1);
}

Node* BTree::CreateFromArray(int *p, int b, int e) {
  if (b > e)
    return NULL;
  int m = b + (e - b) / 2;
  Node *q = new Node(p[m]);
  q->left = CreateFromArray(p, b, m - 1);
  q->right = CreateFromArray(p, m + 1, e);
  return q;
}

void BTree::Clear(Node* p) {
  if (p == NULL)
    return;
  Clear(p->left);
  Clear(p->right);
  delete p;
  p = NULL;
}

BTree::~BTree() {
  Clear(head_);
}

void BTree::Insert(int k) {
  Node *node = new Node(k);
  if (head_ == NULL) {
    head_ = node;
    return;
  }
  Node *pp = NULL, *p = head_;
  while (p != NULL) {
    pp = p;
    if (k <= p->data)
      p = p->left;
    else
      p = p->right;
  }
  if (k <= pp->data)
    pp->left = node;
  else
    pp->right = node;
}

// Treat left pointer as next pointer of singly linked list
void BTree::ConnectLeafsAux(Node *p, Node *&pp, bool FLR, Node *&head) {
  if (p == NULL)
    return;
  if (p->left == NULL && p->right == NULL) {
    //cout << "leaf: " << p->data << endl;
    if (pp != NULL)
      pp->left = p;
    if (head == NULL)
      head = p;
    pp = p;
  } else {
    if (FLR) {
      ConnectLeafsAux(p->left, pp, FLR, head);
      ConnectLeafsAux(p->right, pp, FLR, head);
    } else {
      ConnectLeafsAux(p->right, pp, FLR, head);
      ConnectLeafsAux(p->left, pp, FLR, head);
    }
  }
}

Node* BTree::ConnectLeafs(bool FLR) {
  if (head_ == NULL)
    return NULL;
  Node *h = NULL, *pp = NULL;
  ConnectLeafsAux(head_, pp, FLR, h);
  return h;
}


int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9};  
  BTree tree(arr, sizeof(arr) / sizeof(int));
  Node *h = tree.ConnectLeafs(true);
  while (h != NULL) {
    cout << h->data << " ";
    h = h->left;
  } 
  cout << endl;
}
