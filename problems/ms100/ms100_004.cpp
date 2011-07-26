#include <iostream>
#include <list>
#include <deque>
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
  void FindPathWithSum(int sum) {
    list<int> path;
    FindPathWithSum(root_, path, sum);
  }
  void FindAnyPathWithSum(int sum) {
    deque<int> path;
    FindAnyPathWithSum(root_, path, sum);
  }
private:
  void destroy(BTNode *node);
  void find_sum_path(int s, BTNode *node, int &sum, list<int> &path);
  void FindPathWithSum(BTNode *node, list<int> &path, int sum);
  void FindAnyPathWithSum(BTNode *node, deque<int> &path, int sum);
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

void BTree::find_sum_path(int s, BTNode *node, int &sum, list<int> &path) {
  if (!node) return;
  sum += node->val;
  if (sum > s)
    return;
  else
    path.push_back(node->val);
  if (node->left) find_sum_path(s, node->left, sum, path);
  if (node->right) find_sum_path(s, node->right, sum, path);
  if (!node->left && !node->right && s == sum) { //Leaf
      copy(path.begin(), path.end(), ostream_iterator<int>(cout, " " ));
      cout << endl;
  }
  path.pop_back();
  sum -= node->val;  
}

void BTree::FindPathWithSum(BTNode *node, list<int> &path, int sum) {
  if (!node) return;
  path.push_back(node->val);
  sum -= node->val;
  if (!node->left && !node->right) {
    if (sum == 0) {
      copy(path.begin(), path.end(), ostream_iterator<int>(cout, " " ));
      cout << endl;
    }
  } else {
    if (node->left) FindPathWithSum(node->left, path, sum);
    if (node->right) FindPathWithSum(node->right, path, sum);
  }
  path.pop_back();
}

// Path NOT necessarily from root
void BTree::FindAnyPathWithSum(BTNode *node, deque<int> &path, int sum) {
  if (!node) return;
  path.push_back(node->val);
  deque<int>::iterator it = path.end() - 1;
  int tmp = sum;
  for (; it != path.begin() - 1; --it) {
    tmp -= *it;
    if (tmp == 0) break;
  }
  if (it != path.begin() - 1) {
    copy(it, path.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  FindAnyPathWithSum(node->left, path, sum);
  FindAnyPathWithSum(node->right, path, sum);
  path.pop_back();
}

int main() {
  BTree tr;
  tr.insert(10);
  tr.insert(5);
  tr.insert(12);
  tr.insert(4);
  tr.insert(7);
  tr.insert(2);
  tr.insert(3);
  tr.insert(6);
  tr.insert(8);

  //tr.find_sum_path(19);
  //tr.FindPathWithSum(19);
  tr.FindAnyPathWithSum(23);
}
