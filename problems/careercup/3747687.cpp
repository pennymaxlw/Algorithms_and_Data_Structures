#include <iostream>
using namespace std;

struct BTNode {
  int val;
  BTNode *left;
  BTNode *right;
  BTNode(int v, BTNode *l = NULL, BTNode *r = NULL)
    : val(v), left(l), right(r) {}
};

class BTree {
public:
  BTree(int *arr, int len);
  ~BTree() {Clear(root_);}
  void Boundary();
  void Inorder() {Inorder(root_); cout << endl;}
private:
  BTNode* BuildFromArray(int *arr, int b, int e);
  void Clear(BTNode *node);
  void Inorder(BTNode *node);
  void Boundary(BTNode *node, bool &gotledge);
  void LeftHalfPreorder(BTNode *node, bool &gotledge);
private:
  BTNode *root_;
};

BTree::BTree(int *arr, int len) {
  if (arr == NULL || len < 1) return;
  root_ = BuildFromArray(arr, 0, len - 1);
}

BTNode* BTree::BuildFromArray(int *arr, int b, int e) {
  if (arr == NULL || b > e) return NULL;
  int mid = b + (e - b) / 2;
  BTNode *p = new BTNode(arr[mid]);
  p->left = BuildFromArray(arr, b, mid - 1);
  p->right = BuildFromArray(arr, mid + 1, e);
  return p;
}

void BTree::Clear(BTNode *node) {
  if (node == NULL) return;
  Clear(node->left);
  Clear(node->right);
  delete node;
  node = NULL;
}

void BTree::Inorder(BTNode *node) {
  if (node == NULL) return;
  Inorder(node->left);
  cout << node->val << " ";
  Inorder(node->right);
}

void BTree::Boundary() {
  if (root_ == NULL) return;
  cout << root_->val << " ";
  bool gotledge = false;
  LeftHalfPreorder(root_->left, gotledge);
  Boundary(root_->right, gotledge);
}

void BTree::Boundary(BTNode *node, bool &gotledge) {
  if (node == NULL) return;
  LeftHalfPreorder(node->left, gotledge);
  Boundary(node->right, gotledge);
  cout << node->val << " ";
}

void BTree::LeftHalfPreorder(BTNode *node, bool &gotledge) {
  if (node == NULL) return;
  if (node->left == NULL && node->right == NULL) {
    cout << node->val << " ";
  } else if (!gotledge) {
    cout << node->val << " ";
    if (node->left == NULL) 
      gotledge = true;
  }
  LeftHalfPreorder(node->left, gotledge);
  LeftHalfPreorder(node->right, gotledge);
}


int main() {
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  BTree t(arr, sizeof(arr) / sizeof(int));
  //t.Inorder();
  t.Boundary();
}
