#include <string.h>

#include <map>
#include <stack>
#include <vector>

class CQueue {
 public:
  CQueue() {}

  bool isEmpty() const { return _stack1.empty() && _stack2.empty(); }

  void appendTail(int value) { _stack1.push(value); }

  int deleteHead() {
    if (isEmpty()) {
      return -1;
    }

    if (_stack2.empty()) {
      while (!_stack1.empty()) {
        _stack2.push(_stack1.top());
        _stack1.pop();
      }
    }
    int valtop = _stack2.top();
    _stack2.pop();
    return valtop;
  }

 private:
  std::stack<int> _stack1;
  std::stack<int> _stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
