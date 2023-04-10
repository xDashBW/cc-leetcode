#include <algorithm>
#include <vector>

class Solution {
 public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    for (auto i : nums2) {
      auto iter = std::find(nums1.begin(), nums1.end(),
                            [i](int &val) -> bool { return val > i; });
      nums1.insert(iter, i);
    }
  }
};
