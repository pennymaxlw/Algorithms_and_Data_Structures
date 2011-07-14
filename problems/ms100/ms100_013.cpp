#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};

ListNode* ReverseKthNode(ListNode *head, int k) {
  if (!head) return NULL;
  ListNode *left = head, *right = head;
  int i = 0;
  while (i++ < k - 1) {
    if (right->next)
      right = right->next;
    else
      return NULL;
  }
  while (right->next) {
    left = left->next;
    right = right->next;
  }
  return left;
}

int main() {
  ListNode *head = NULL, *p = NULL;
  for (int i = 10; i >= 1; --i) {
    p = new ListNode;
    p->val = i;
    p->next = head;
    head = p;
  }
  
  ListNode *rev_k = ReverseKthNode(head, 10);
  if (rev_k)
    cout << "Answer is: " << rev_k->val << endl;
  else
    cerr << "Invalid reverse k!!" << endl;
}


