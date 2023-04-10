#include <stack>

class MyQueue {
 public:
  std::stack<int> stack1;
  std::stack<int> stack2;

  MyQueue() {}

  void push(int x) { stack1.push(x); }

  int pop() {
    int i = peek();
    stack2.pop();
    return i;
  }

  int peek() {
    if (stack2.empty()) {
      while (stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    return stack2.top();
  }

  bool empty() { return stack1.empty() && stack2.empty(); }
};
