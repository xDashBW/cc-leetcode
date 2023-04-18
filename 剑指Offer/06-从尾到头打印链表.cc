#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    std::stack<int> mqueue;
    std::vector<int> vec;

    while (head) {
      mqueue.push(head->val);
      head = head->next;
    }

    while (!mqueue.empty()) {
      vec.push_back(mqueue.top());
      mqueue.pop();
    }

    return vec;
  }
};