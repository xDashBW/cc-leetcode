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
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    ListNode *brk = nullptr;
    while (fast && fast->next) {
      if (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
      }
      if (fast == nullptr || fast->next == nullptr) {
        brk = slow;
      }
      slow = slow->next;
    }
    brk->next = nullptr;

    ListNode *head1 = sortList(head);
    ListNode *head2 = sortList(slow);

    ListNode dummy;
    ListNode *iter = &dummy;
    while (head1 || head2) {
      if (head2 == nullptr ||
          (head1 != nullptr && head2 != nullptr && head1->val < head2->val)) {
        iter->next = head1;
        iter = head1;
        head1 = head1->next;
      } else {
        iter->next = head2;
        iter = head2;
        head2 = head2->next;
      }
    }
    return dummy.next;
  }
};