

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *p = reverseList(head);
    head->next->next = head;
    head->next = nullptr;
    return p;
  }

  // ListNode* reverseList(ListNode* head) {
  //   ListNode *ptr = head;
  //   ListNode *prev = NULL, *next = NULL;

  //   while (ptr) {
  //     next = ptr->next;
  //     ptr->next = prev;
  //     prev = ptr;
  //     ptr = next;
  //   }

  //   return prev;
  // }
};