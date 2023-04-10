#include <vector>

class MyCircularDeque {
 public:
  std::vector<int> _queue;
  int _head;
  int _tail;
  int _size;

  MyCircularDeque(int k) : _queue(k, 0), _head(-1), _tail(-1), _size(k) {}

  bool insertFront(int value) {
    if (_head == 0) {
      return false;
    }

    if (_head == -1) {
      _queue[0] = value;
      _head = 0;
      _tail = 0;
    } else {
      _queue[--_head] = value;
    }

    return true;
  }

  bool insertLast(int value) {
    if (_tail == _size - 1) {
      return false;
    }

    if (_tail == -1) {
      _queue[0] = value;
      _head = 0;
      _tail = 0;
    } else {
      _queue[++_tail] = value;
    }

    return true;
  }

  bool deleteFront() {}

  bool deleteLast() {}

  int getFront() {}

  int getRear() {}

  bool isEmpty() { return _head == -1; }

  bool isFull() { return _head == 0 && _tail == _size - 1; }
};
