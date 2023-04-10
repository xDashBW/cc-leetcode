#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    if (head->next == nullptr) {
      return true;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *brk = nullptr;

    while (1) {
      if (!fast || !fast->next) {
        if (fast) {
          slow = slow->next;
        }
        break;
      }
      fast = fast->next->next;
      // 1 2 1
      if (!fast || !fast->next) {
        brk = slow;
      }
      slow = slow->next;
    }
    if (brk == nullptr) {
      brk = head;
    }

    brk->next = nullptr;

    // reverse [head, nullptr]
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    for (ListNode *iter = head; iter;) {
      next = iter->next;
      iter->next = prev;
      prev = iter;
      iter = next;
    }
    head = prev;

    while (head && slow) {
      if (head->val != slow->val) {
        break;
      }
      slow = slow->next;
      head = head->next;
    }

    if (!head)
      return false;
    else
      return true;
  }
};