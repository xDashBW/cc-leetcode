#include <iostream>
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

    set.clear();

    for (ListNode *p = headA; p; p = p->next) {
      set.insert(p);
    }

    for (ListNode *p = headB; p; p = p->next) {
      auto iter = set.find(p);
      if (iter != set.end()) {
        return p;
      }
    }
    return nullptr;
  }
};

int main() { std::cout << "fuckyou" << std::endl; }
