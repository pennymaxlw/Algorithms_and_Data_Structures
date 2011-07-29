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
  int LcaAux2(BSTNode *node, int i, int j, BSTNode *&lca);
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

int BSTree::LcaAux(BSTNode *node, int i, int j, BSTNode *&lca) {
  //cout << "node " << node->val << endl;
  if (!node) return 0;
  if (!lca) {
    int lcnt = 0, rcnt = 0;
    if (node->left) lcnt = LcaAux(node->left, i, j, lca);
    if (node->right) rcnt = LcaAux(node->right, i, j, lca);
    if (lcnt == 2 || rcnt == 2) return 2;  //Found in left or right subtree
    if (node->val == i || node->val == j) {
      if (lcnt == 1 || rcnt == 1) {       //i and j are on the same line
        lca = node;
        return 2;
      } else                              //Found one matching 
        return 1;
    } else {
      if (lcnt + rcnt == 2)               //i and j are in left and right subtree
        lca = node;
      return lcnt + rcnt;
    }
  } 
  return 2;                               //Have found lca, return val is not important
}

int BSTree::LcaAux2(BSTNode *root, int i, int j, BSTNode *&lca) {
  if (!root) return 0;
  if (lca) return 2;
  int l = LcaAux2(root->left, i, j, lca);
  int r = LcaAux2(root->right, i, j, lca);
  if (root->val == i || root->val == j)
    return l + r + 1;
  if (l + r == 2 && !lca)
    lca = root;
  return l + r;
}

int BSTree::Lca(int i, int j) {
  BSTNode *lca = NULL;
  //LcaAux(root_, i, j, lca);
  LcaAux2(root_, i, j, lca);
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
