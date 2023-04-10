
#include <utility>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *iter = head;
    ListNode *prev = nullptr;
    ListNode *mhead = nullptr, *first = nullptr;
    --left, --right;

    for (int i = 0; iter; ++i) {
      if (left != 0 && i == left - 1) {
        mhead = iter;
      }
      if (i >= left && i <= right) {
        if (i == left) {
          first = iter;
        }
        ListNode *next = iter->next;
        iter->next = prev;
        prev = iter;
        iter = next;

        if (i == right) {
          first->next = iter;
          if (left == 0) {
            head = prev;
          } else {
            mhead->next = prev;
          }
        }
      } else {
        iter = iter->next;
      }
    }
    return head;
  }
};
