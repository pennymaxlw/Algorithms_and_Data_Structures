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
  int Lca(int i, int j);
private:
  void ClearAux(BSTNode *node);
  int LcaAux(BSTNode *node, int i, int j, BSTNode *&lca);
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

int BSTree::LcaAux(BSTNode *root, int i, int j, BSTNode *&lca) {
  if (!root) return 0;
  if (lca) return 2;
  int l = LcaAux(root->left, i, j, lca);
  int r = LcaAux(root->right, i, j, lca);
  if (root->val == i || root->val == j)
    return l + r + 1;
  if (l + r == 2 && !lca)
    lca = root;
  return l + r;
}

int BSTree::Lca(int i, int j) {
  BSTNode *lca = NULL;
  LcaAux(root_, i, j, lca);
  if (lca) return lca->val;
  else return -1; 
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

  while (cin) {
    cout << endl;
    int i = 0, j = 0;
    cout << "Please input two nodes" << endl;
    cin >> i;
    cin >> j;
    cout << "LCA of " << i << " and " << j << ": "
         << tree.Lca(i, j)
         << endl;
  }
}
