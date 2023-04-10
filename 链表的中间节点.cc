#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *middleNode(ListNode *head) {
    int sz = 0;
    ListNode *iter = head;
    while (iter) {
      ++sz;
      iter = iter->next;
    }

    int mindle = sz / 2;

    iter = head;
    for (int i = 0; i < sz; ++i) {
      iter = iter->next;
    }
    return iter;
  }
};