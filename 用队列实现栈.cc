
#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>

class MyStack {
 public:
  std::queue<int> _queue1;
  std::queue<int> _queue2;
  bool _is_use_1;

  MyStack() : _is_use_1(true) {}

  void push(int x) {
    if (_is_use_1) {
      _queue1.push(x);
    } else {
      _queue2.push(x);
    }
  }

  int pop() {
    std::queue<int> *used = nullptr;
    std::queue<int> *buff = nullptr;

    if (_is_use_1) {
      used = &_queue1;
      buff = &_queue2;
    } else {
      used = &_queue2;
      buff = &_queue1;
    }

    auto sz = used->size();
    for (decltype(sz) i = 0; i < sz - 1; ++i) {
      buff->push(used->front());
      used->pop();
    }
    int val = used->front();
    used->pop();
    if (_is_use_1) {
      _is_use_1 = false;
    } else {
      _is_use_1 = true;
    }
    return val;
  }

  int top() {
    std::queue<int> *used = nullptr;
    std::queue<int> *buff = nullptr;

    if (_is_use_1) {
      used = &_queue1;
      buff = &_queue2;
    } else {
      used = &_queue2;
      buff = &_queue1;
    }

    assert(buff->size() == 0);
    auto sz = used->size();
    for (decltype(sz) i = 0; i < sz - 1; ++i) {
      buff->push(used->front());
      used->pop();
    }
    assert(used->size() == 1);
    int val = used->front();
    used->pop();
    buff->push(val);
    if (_is_use_1) {
      _is_use_1 = false;
    } else {
      _is_use_1 = true;
    }
    return val;
  }

  bool empty() { return _queue1.empty() && _queue2.empty(); }
};

int main() {
  MyStack s;
  s.push(1);
  s.push(2);
  s.push(3);
  int ret = s.top();
  std::cout << ret << std::endl;
}