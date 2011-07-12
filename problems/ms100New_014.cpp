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
friend int MedianUpperBound(BSTree &tree);
public:
  BSTree() : root_(NULL) {}
  BSTree(int arr[], int len);
  ~BSTree() {Clear(root_);}
  void Insert(int t);
  int Min();
  int Max();
private:
  void Clear(BSTNode *node);
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

int BSTree::Min() {
  if (!root_) return -1;
  BSTNode *p = root_;
  while (p->left) p = p->left;
  return p->val;
}

int BSTree::Max() {
  if (!root_) return -1;
  BSTNode *p = root_;
  while (p->right) p = p->right;
  return p->val;
}

void MedianUpperBoundAux(BSTNode *node, int t, BSTNode *&result) {
  if (!node || result) return;
  MedianUpperBoundAux(node->left, t, result);
  if (node->val > t) {
    result = node;
    return;
  }
  MedianUpperBoundAux(node->right, t, result);
}

int MedianUpperBound(BSTree &tree) {
  if (!tree.root_) return -1;
  int mid = (tree.Min() + tree.Max()) / 2;
  BSTNode *result = NULL;
  MedianUpperBoundAux(tree.root_, mid, result);
  if (result) 
    return result->val;
  else 
    return -1;
}


int main() {
  int arr[] = {4,5,6,7,8,10,11,12,13,160};
  BSTree tree(arr, sizeof(arr) / sizeof(int));
  int result = MedianUpperBound(tree);
  cout << "Median upper bound is " << result << endl;
}
