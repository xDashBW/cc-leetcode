
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *iter = head;

    while (iter) {
      if (iter->next && iter->next->val == iter->val) {
        iter->next = iter->next->next;
      } else {
        iter = iter->next;
      }
    }

    return head;
  }
};