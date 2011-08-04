#include <iostream>
#include <vector>
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
  void RebuildFromPreInOrder(vector<int> &pre, vector<int> &in);
  void BreadthFirstTraversal();
private:
  void Clear(BSTNode *node);
  BSTNode* RebuildFromPreInOrderAux(vector<int> &pre, int rootidx,
                                 vector<int> &in, int subfirst, int sublast);
  BSTNode* RebuildFromPreInOrderAux2(int *pre, int prelen, int *in, int inlen);
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

BSTNode* BSTree::RebuildFromPreInOrderAux(vector<int> &pre, int rootidx,
                                 vector<int> &in, int subfirst, int sublast) {
  //cout << "rootidx " << rootidx << " subfirst " << subfirst << " sublast " << sublast << endl;  
  if (rootidx >= pre.size()) return NULL;
  BSTNode *p = new BSTNode(pre[rootidx]);
  int i = subfirst;
  while (i <= sublast && in[i] != pre[rootidx]) ++i;
  if (i > sublast) return NULL;
  if (subfirst <= i - 1)
    p->left = RebuildFromPreInOrderAux(pre, rootidx + 1, in, subfirst, i - 1);
  if (i + 1 <= sublast)
    p->right = RebuildFromPreInOrderAux(pre, rootidx + 1 + i - subfirst, in, i + 1, sublast);
  return p;
}

BSTNode* BSTree::RebuildFromPreInOrderAux2(int *pre, int prelen, int *in, int inlen) {
  if (pre == NULL || in == NULL || prelen < 1 || inlen < 1)
    return NULL;
  BSTNode *p = new BSTNode(pre[0]);
  int i = 0;
  for (; i < inlen; ++i)
    if (in[i] == pre[0]) break;
  if (i >= inlen) return NULL;
  p->left = RebuildFromPreInOrderAux2(pre + 1, i, in, i);
  p->right = RebuildFromPreInOrderAux2(pre + i + 1, inlen - i - 1, in + i + 1, inlen - i - 1);
  return p;
}

void BSTree::RebuildFromPreInOrder(vector<int> &pre, vector<int> &in) {
  if (pre.empty() || in.empty() || pre.size() != in.size()) return;
  Clear(root_);
  root_ = RebuildFromPreInOrderAux(pre, 0, in, 0, in.size() - 1);
  //root_ = RebuildFromPreInOrderAux2(&pre[0], pre.size(), &in[0], in.size());
}

void BSTree::BreadthFirstTraversal() {
  if (!root_) return;
  vector<BSTNode*> aux;
  int first = 0, last = 0;  
  aux.push_back(root_);
  BSTNode *p = NULL;
  while (first <= last) {
    p = aux[first];
    cout << p->val << " ";
    ++first;
    if (p->left) {
      aux.push_back(p->left);
      ++last;
    }
    if (p->right) {
      aux.push_back(p->right);
      ++last;
    }
  }
  cout << endl;
}

int main() {
  //int arr[] = {10,7,12,8,9,11};
  //BSTree tree(arr, sizeof(arr) / sizeof(int));
  BSTree tree;
  int arrpre[] = {1,2,4,3,5,6};
  int arrin[] = {4,2,1,5,3,6};
  //int arrpre[] = {1,2,3,4,5,6};
  //int arrin[] = {6,5,4,3,2,1};
  vector<int> pre(arrpre, arrpre + sizeof(arrpre) / sizeof(int)); 
  vector<int> in(arrin, arrin + sizeof(arrin) / sizeof(int)); 
  tree.RebuildFromPreInOrder(pre, in);
  cout << "\nBreadth First Traversal:" << endl;
  tree.BreadthFirstTraversal();
}
