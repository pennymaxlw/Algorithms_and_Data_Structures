#include <iostream>
using namespace std;

struct BSTNode {
  int val;
  BSTNode *left;
  BSTNode *right;
  BSTNode(int i = 0, BSTNode *l = NULL, BSTNode *r = NULL)
    : val(i), left(l), right(r) {}
};

class BSTree {
public:
  BSTree() : root_(NULL) {}
  BSTree(int arr[], int len);
  ~BSTree() {Clear(root_);}
  void Insert(int t);
  bool IfBanlance();
private:
  void Clear(BSTNode *node);
  bool IfBanlanceAux(BSTNode *node, int &height);
private:
  BSTNode *root_;
};

BSTree::BSTree(int arr[], int len)
  : root_(NULL) {
  for (int i = 0; i < len; ++i)
    Insert(arr[i]);
}

void BSTree::Clear(BSTNode *node) {
  if (!node) return;
  Clear(node->left);
  Clear(node->right);
  delete node;
  node = NULL;
}

void BSTree::Insert(int t) {
  BSTNode *node = new BSTNode(t);
  if (!root_) {
    root_ = node;
    return;
  }
  BSTNode *p = root_;
  BSTNode *pp = NULL;
  while (p) {
    pp = p;
    if (t <= p->val) p = p->left;
    else p = p->right;
  }
  if (t <= pp->val) pp->left = node;
  else pp->right = node;
}

bool BSTree::IfBanlance() {
  int h = 0;
  return IfBanlanceAux(root_, h);
}

bool BSTree::IfBanlanceAux(BSTNode *node, int &height) {
  if (!node) {
    height = 0;
    return true;
  }
  int lh = 0, rh = 0, diff = 0;
  if (IfBanlanceAux(node->left, lh) && 
      IfBanlanceAux(node->right, rh)) {
    diff = lh - rh;
    if (diff >= -1 && diff <= 1) {
      height = 1 + (lh > rh ? lh : rh);
      return true;
    }
  }
  return false;
}

int main() {
  int arr[] = {10,7,12,8,9,11};
  BSTree tree(arr, sizeof(arr) / sizeof(int));
  if (tree.IfBanlance())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
