#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;

struct BSTNode {
  int val;
  BSTNode *left;
  BSTNode *right;
  BSTNode(int i = 0, BSTNode *l = NULL, BSTNode *r = NULL)
    : val(i), left(), right(NULL) {}
};

class BSTree {
public:
  BSTree() : root_(NULL) {}
  ~BSTree() {Clear();}
  void Clear();
  void Insert(int i);
  void Rotate() {
    if (!root_) return;
    Rotate(root_);
  }
  void RotateIterative();
  void RotateIterative2();
  void BreadthFirstTraversal();
private:
  void ClearAux(BSTNode *node);
  void Rotate(BSTNode *node);
private:
  BSTNode *root_;
};

void BSTree::Clear() {
  ClearAux(root_);
  root_ = NULL;
}

void BSTree::ClearAux(BSTNode *node) {
  if (node) {
    ClearAux(node->left);
    ClearAux(node->right);
    delete node;
  }
}

void BSTree::Insert(int i) {
  if (!root_) {
    root_ = new BSTNode(i);
    return;
  }
  BSTNode *p = root_;
  BSTNode *pp = root_;
  while (p) {
    pp = p;
    if (i <= p->val)
      p = p->left;
    else
      p = p->right;
  }
  p = new BSTNode(i);
  if (i <= pp->val)
    pp->left = p;
  else
    pp->right = p;
}

void BSTree::Rotate(BSTNode *node) {
  if (!node) return;
  BSTNode *tmp = node->left;
  node->left = node->right;
  node->right = tmp;
  if (node->left) Rotate(node->left);
  if (node->right) Rotate(node->right);
}

void BSTree::RotateIterative() {
  if (!root_) return; 
  stack<BSTNode*> stack;  
  stack.push(root_);
  BSTNode *curr = root_;
  BSTNode *tmp = NULL;
  while (!stack.empty()) {
    curr = stack.top();
    stack.pop();
    tmp = curr->left;
    curr->left = curr->right;
    curr->right = tmp;
    if (curr->left) stack.push(curr->left);
    if (curr->right) stack.push(curr->right);
  }
}

void BSTree::RotateIterative2() {
  if (!root_) return;
  stack<BSTNode*> s;
  BSTNode *p = root_;
  while (p || !s.empty()) {
    if (p) {
      s.push(p);
      swap(p->left, p->right);
      p = p->left;
    } else {
      p = s.top();
      s.pop();
      p = p->right;
    }
  }
}

void BSTree::BreadthFirstTraversal() {
  if (!root_) return;
  queue<BSTNode*> qu;
  BSTNode *p = root_;  
  qu.push(root_); 
  while (!qu.empty()) {
    p = qu.front();
    qu.pop();
    if (p->left) qu.push(p->left);
    if (p->right) qu.push(p->right);
    cout << p->val << " ";
  }
  cout << endl;
}


int main() {
  BSTree tree;
  tree.Insert(8);
  tree.Insert(6);
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(7);
  tree.Insert(9);
  tree.Insert(11);

  tree.BreadthFirstTraversal();
  //tree.Rotate();
  //tree.BreadthFirstTraversal();
  tree.RotateIterative2();
  tree.BreadthFirstTraversal();
}
