struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (!head->next) {
      return true;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *brk = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      if (!fast || !fast->next) {
        brk = slow;
      }
      slow = slow->next;
    }
    brk->next = nullptr;
    if (fast) {
      slow = slow->next;
    }

    ListNode *iter = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (iter) {
      next = iter->next;
      iter->next = prev;
      prev = iter;
      iter = next;
    }
    head = prev;

    while (head) {
      if (head->val != slow->val) {
        break;
      }
      head = head->next;
      slow = slow->next;
    }
    return !head;
  }
};