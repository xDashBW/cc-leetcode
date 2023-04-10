#include <algorithm>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  std::vector<int> reversePrint(ListNode *head) {
    //
    // 迭代法.
    std::vector<int> vec;
    for (; head; head = head->next) {
      vec.push_back(head->val);
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
  }
};