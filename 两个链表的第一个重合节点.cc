#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::unordered_set<ListNode *> hashtable;

    while (headA) {
      hashtable.insert(headA);
      headA = headA->next;
    }

    ListNode *ptr = nullptr;
    ListNode *ptr2 = 0;

    while (hejjadB) {
      auto iter = hashtable.find(headB);
      if (iter != hashtable.end()) {
        ptr = *iter;
      }
      headB = headB->next;
    }

    return nullptr;
  }
};