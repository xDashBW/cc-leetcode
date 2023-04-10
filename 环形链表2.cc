#include <unordered_set>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    std::unordered_set<ListNode *> set;

    while (head) {
      auto iter = set.find(head);
      if (iter == set.end()) {
        set.insert(head);
      } else {
        head = *iter;
        break;
      }
      head = head->next;
    }
    return head;
  }
};