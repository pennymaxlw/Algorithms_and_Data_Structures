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

BTNode* BuildBinTreeFromArray2(int *arr, int start, int end) {
  if (!arr || start > end) return NULL;
  int mid = start + (end - start) / 2;
  BTNode *p = new BTNode(arr[mid]);
  p->left = BuildBinTreeFromArray2(arr, start, mid - 1);
  p->right = BuildBinTreeFromArray2(arr, mid + 1, end);
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
 //BTNode *head = BuildBinTreeFromArray2(arr, sizeof(arr) / sizeof(int));
 int pos = 0;
 BTNode *head = BuildBinTreeFromArray2(arr, 0, sizeof(arr) / sizeof(int) - 1);
 TraversalBinTree(head);
 cout << endl;
}
