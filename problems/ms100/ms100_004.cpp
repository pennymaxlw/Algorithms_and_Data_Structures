#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

struct BTNode {
  int val;
  BTNode *left, *right;
  BTNode(int i = 0, 
      BTNode *l = NULL, 
      BTNode *r = NULL)
    : val(i), left(l), right(r) {}
};

class BTree {
public:
  BTree() : root_(NULL) {}
  ~BTree() {destroy(root_);}
  void insert(int i);
  void find_sum_path(int s) {
    int sum = 0;
    list<int> path;
    find_sum_path(s, root_, sum, path);
  }
private:
  void destroy(BTNode *node);
  void find_sum_path(int s, BTNode *node, int sum, list<int> &path);
private:
  BTNode* root_;
};

void BTree::destroy(BTNode *node) {
  if (node) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

void BTree::insert(int i) {
  if (!root_) {
    root_ = new BTNode(i);
    return;
  }
  BTNode *p = root_;
  while (1) {
    if (i <= p->val) {
      if (p->left) {
        p = p->left;
      } else {
        p->left = new BTNode(i);
        break;
      }
    } else {
      if (p->right) {
          p = p->right;
      } else {
        p->right = new BTNode(i);
        break;
      }
    }
  }
}

void BTree::find_sum_path(int s, BTNode *node, int sum, list<int> &path) {
  if (node) {
    sum += node->val;
    path.push_back(node->val);
    if (sum < s) {
      list<int> path1(path), path2(path);
      find_sum_path(s, node->left, sum, path1);
      find_sum_path(s, node->right, sum, path2);
    } else if (sum == s) {
      cout << "Found path: ";
      copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
    } else {
      return;
    }
  }
}

int main() {
  BTree tr;
  tr.insert(10);
  tr.insert(5);
  tr.insert(12);
  tr.insert(4);
  tr.insert(7);

  tr.find_sum_path(22);
}
