#include <iostream>
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
  int Height();
private:
  void ClearAux(BSTNode *node);
  int HeightAux(BSTNode *node);
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

int BSTree::Height() {
  if (!root_) return 0;
  HeightAux(root_);
}

int BSTree::HeightAux(BSTNode *node) {
  if (!node) return 0;
  int lh = 0, rh = 0;
  if (node->left) lh = HeightAux(node->left);
  if (node->right) rh = HeightAux(node->right);
  return lh > rh ? lh + 1 : rh + 1;
}


int main() {
  BSTree tree;
  tree.Insert(16);
  //tree.Insert(12);
  //tree.Insert(24);
  //tree.Insert(10);
  //tree.Insert(14);
  //tree.Insert(23);
  //tree.Insert(25);
  //tree.Insert(22);
  //tree.Insert(26);
  //tree.Insert(21);
  //tree.Insert(28);
  //tree.Insert(20);
  //tree.Insert(30);
  
  cout << "Tree height is " << tree.Height() << endl;
  
}
