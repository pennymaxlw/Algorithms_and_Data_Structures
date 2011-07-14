#include <iostream>
using namespace std;

struct BTNode {
  int val;
  BTNode *left;
  BTNode *right;
  BTNode(int v = 0, BTNode *l = NULL, BTNode *r = NULL)
    : val(v), left(l), right(r) {}
};

BTNode* BuildBinTreeFromArray(int *arr, int len, int pos = 0) {
  if (!arr) return NULL;
  BTNode *p = NULL;
  if (pos < len) {
    p = new BTNode(arr[pos]);
    p->left = BuildBinTreeFromArray(arr, len, 2 * pos + 1);
    p->right = BuildBinTreeFromArray(arr, len, 2 * pos + 2);
  }
  return p;
}

void TraversalBinTree(BTNode *head) {
  if (head) {
    if (head->left) TraversalBinTree(head->left);
    cout << head->val << " ";
    if (head->right) TraversalBinTree(head->right);
  }
}


int main() {
 int arr[] = {1,2,3,4,5,6,7,8,9};
 BTNode *head = BuildBinTreeFromArray(arr, sizeof(arr) / sizeof(int));
 TraversalBinTree(head);
 cout << endl;
}
