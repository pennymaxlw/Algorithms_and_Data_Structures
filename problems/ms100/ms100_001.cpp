#include <iostream>
using namespace std;

struct BSTNode {
  int val;
  BSTNode* left;
  BSTNode* right;
  BSTNode(int i = 0, BSTNode *l = NULL, BSTNode *r = NULL) 
    : val(i), left(l), right(r) {}
};

class BSTree {
public:
  BSTree() : root_(NULL), dlist_head_(NULL), dlist_cur_(NULL) {} 
  ~BSTree();
  void insert(int i);
  BSTNode* convert_to_dlist();
private:
  void convert_to_dlist(BSTNode *node);
  void destroy(BSTNode *node);
private:
  BSTNode* root_;
  BSTNode* dlist_head_;
  BSTNode* dlist_cur_;
};

void BSTree::insert(int i) {
  if (!root_) {
    root_ = new BSTNode(i);
    return;
  } 
  BSTNode* p = root_;
  while (1) {
    if (i <= p->val) {
      if (p->left) {
        p = p->left;
      } else {
        p->left = new BSTNode(i);      
        break;
      }
    } else {
      if (p->right) {
        p = p->right;
      } else {
        p->right = new BSTNode(i);      
        break;
      }
    }
  }
}

BSTree::~BSTree() {
  destroy(root_);
}

void BSTree::destroy(BSTNode *node) {
  if (node) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

void BSTree::convert_to_dlist(BSTNode *node) {
  if (node) {
    convert_to_dlist(node->left);
    if (!dlist_head_) {
      dlist_head_ = dlist_cur_ = node;
    }
    else {
      dlist_cur_->right = node;
      node->left = dlist_cur_; 
      dlist_cur_ = node;
    }
    convert_to_dlist(node->right);
  }  
}

BSTNode* BSTree::convert_to_dlist() {
  convert_to_dlist(root_);
  return dlist_head_;
}

int main() {
  BSTree tr;
  tr.insert(10);
  tr.insert(6);
  tr.insert(14);
  tr.insert(4);
  tr.insert(8);
  tr.insert(12);
  tr.insert(16);

  BSTNode* head = tr.convert_to_dlist();
  while (head) {
    cout << head->val << " ";
    head = head->right;
  }
  cout << endl;
}
