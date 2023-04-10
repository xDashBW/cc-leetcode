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
  void reorderList(ListNode *head) {
    std::vector<ListNode *> vec;

    for (ListNode *ptr = head; ptr; ptr = ptr->next) {
      vec.push_back(ptr);
    }

    ListNode *curr = head;
    int i = 1;
    int j = vec.size() - 1;
    for (int r = 0; curr; ++r) {
      if (r % 2 == 0) {
        curr->next = vec[j];
        --j;
      } else {
        curr->next = vec[i];
        ++i;
      }
      curr = curr->next;
    }
  }
};

int main() {
  ListNode head;
  ListNode *curr = &head;
  // 构建一个链表头，
  // head->
  // had,cxo
  //
  for (int i = 0; i < 5; ++i) {
    if (i == 0) {
      head.next = new ListNode(i);
      curr = head.next;
    } else {
      curr = head.next;
    }
  }
}