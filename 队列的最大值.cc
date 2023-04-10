#include <queue>
#include <utility>
#include <vector>

struct myCompare {
  bool operator()(std::pair<int, bool> *&l, std::pair<int, bool> *&r) {
    return l->first < r->first;
  }
};

class MaxQueue {
 public:
  MaxQueue() {}

  int max_value() {
    if (_queue.size() == 0) {
      return -1;
    }
    int ret = 0;
    while (1) {
      std::pair<int, bool> *maxv = _pri_queue.top();
      if (maxv->second) {
        ret = maxv->first;
        break;
      }
      _pri_queue.pop();
      delete maxv;
    }
    return ret;
  }

  void push_back(int value) {
    std::pair<int, bool> *a = new std::pair<int, bool>(value, true);
    _queue.push(a);
    _pri_queue.push(a);
  }

  int pop_front() {
    if (_queue.size() == 0) {
      return -1;
    }
    std::pair<int, bool> *topv = _queue.front();
    _queue.pop();
    topv->second = false;
    return topv->first;
  }

 private:
  std::queue<std::pair<int, bool> *> _queue;
  std::priority_queue<std::pair<int, bool> *,
                      std::vector<std::pair<int, bool> *>, myCompare>
      _pri_queue;
};
