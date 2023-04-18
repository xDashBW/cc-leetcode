#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::unordered_set<ListNode *> set;
    for (; headA; headA = headA->next) {
      set.insert(headA);
    }
    for (; headB; headB = headB->next) {
      auto ret = set.find(headB);
      if (ret != set.end()) {
        break;
      }
    }
    return headB;
  }
};