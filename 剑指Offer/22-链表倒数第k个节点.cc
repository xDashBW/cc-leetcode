#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    std::vector<ListNode*> vec;

    for (ListNode *iter = head; iter; iter = iter->next) {
      vec.push_back(iter);
    }
    return vec[vec.size() - k];
  }
};