#include <unordered_set>
#include <vector>

class Solution {
 public:
  int findRepeatNumber(std::vector<int>& nums) {
    std::unordered_set<int> set;
    int ret = 0;
    for (auto i : nums) {
      auto iter = set.find(i);
      if (iter == set.end()) {
        set.insert(i);
      } else {
        ret = i;
        break;
      }
    }
    return ret;
  }
};