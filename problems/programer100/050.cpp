#include <iostream>
using namespace std;

struct BTNode {
  int val;
  BTNode *left;
  BTNode *right;
  BTNode(int i = 0, BTNode *l = NULL, BTNode *r = NULL)
    : val(i), left(l), right(r) {}
};

class BTree {
friend bool CheckIfSubTree(BTree &tree, BTree &subtree);
public:
  BTree() : root_(NULL) {}
  BTree(int *arr, int len);
  ~BTree();
private:
  BTNode* FromArray(int *arr, int len, int pos);
  void Clear(BTNode *node);
private:
  BTNode *root_;
};

BTree::BTree(int *arr, int len)
{
  root_ = FromArray(arr, len, 0); 
}

BTNode* BTree::FromArray(int *arr, int len, int pos) {
  if (!arr) return NULL;
  BTNode *p = NULL;
  if (pos < len) {
    p = new BTNode(arr[pos]);
    p->left = FromArray(arr, len, 2 * pos + 1);
    p->right = FromArray(arr, len, 2 * pos + 2);
  }
  return p;
}

BTree::~BTree() {
  Clear(root_);
}

void BTree::Clear(BTNode *node) {
  if (!node) return;
  Clear(node->left);
  Clear(node->right);
  delete node;
  node = NULL;
}

bool CheckIfSubTreeAux(BTNode *p, BTNode *sp) {
  if (sp == NULL) return true;
  if (p == NULL) return false;
  if (p->val == sp->val) {
    return CheckIfSubTreeAux(p->left, sp->left) &&
           CheckIfSubTreeAux(p->right, sp->right);
  } else {
    return CheckIfSubTreeAux(p->left, sp) ||
           CheckIfSubTreeAux(p->right, sp);
  }
}

bool CheckIfSubTree(BTree &tree, BTree &subtree) {
  BTNode *p = tree.root_;
  BTNode *sp = subtree.root_;
  if (!p || !sp) return false;
  return CheckIfSubTreeAux(p, sp);
}


int main() {
  int arr[] = {1,8,7,9,2,4,7,3,0,1,5};
  int arr2[] = {8,9,2,3,0};
  BTree tree(arr, sizeof(arr) / sizeof(int));
  BTree subtree(arr2, sizeof(arr2) / sizeof(int));
  if (CheckIfSubTree(tree, subtree))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

