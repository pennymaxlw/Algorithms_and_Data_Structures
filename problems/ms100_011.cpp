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
  int FindMaxDistance();
private:
  void ClearAux(BSTNode *node);
  int FindMaxDistanceAux(BSTNode *node, int &max);
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

int BSTree::FindMaxDistance() {
  if (!root_)
    return -1;
  int max = 0;
  FindMaxDistanceAux(root_, max);   
  return max;
}

int BSTree::FindMaxDistanceAux(BSTNode *node, int &max) {
  int left_h = 0, right_h = 0;
  if (node->left) {
    left_h = FindMaxDistanceAux(node->left, max);
    left_h += 1;
  }
  if (node->right) {
    right_h = FindMaxDistanceAux(node->right, max);
    right_h += 1;
  } 
  int curr = left_h + right_h;
  if (curr > max) {
    max = curr;
  }
  if (left_h > right_h)
    return left_h;
  else
    return right_h;
}


int main() {
  BSTree tree;
  tree.Insert(16);
  tree.Insert(12);
  tree.Insert(24);
  tree.Insert(10);
  tree.Insert(14);
  tree.Insert(23);
  tree.Insert(25);
  tree.Insert(22);
  tree.Insert(26);
  tree.Insert(21);
  tree.Insert(28);
  tree.Insert(20);
  tree.Insert(30);
  
  int max = tree.FindMaxDistance();
  cout << "Max distance: " << max << endl;
}
