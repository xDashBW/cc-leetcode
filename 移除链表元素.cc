
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *iter = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while (iter) {
      if (val == iter->val) {
        if (prev == nullptr) {
          head = head->next;
          iter = head;
          continue;
        }

        prev->next = iter->next;
        iter = iter->next;
      } else {
        prev = iter;
        iter = iter->next;
      }
    }

    return head;
  }
};