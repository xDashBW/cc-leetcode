
#include <iostream>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int> &nums) {
    // 1 10 -5 -6  5
    // j   i

    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int ret = 0;
    int sums = 0;
    std::vector<int>::size_type i = 0, j = 0;
    for (; i != nums.size(); ++i) {
      if (nums[i] >= 0) {
        sums += nums[i];
        continue;
      }

      if (sums + nums[i] < 0) {
        j = i + 1;
        sums = 0;
      } else {
        if (sums > ret) {
          ret = sums;
        }

        sums += nums[i];
      }
    }
    return ret;
  }

  // int maxSubArray(std::vector<int>& nums) {
  //   int max_val = 0;
  //   for (std::vector<int>::size_type i = 0; i != nums.size(); ++i) {
  //     int sum = 0;
  //     for (auto j = i; j != nums.size(); ++j) {
  //       sum += nums[j];
  //       if (sum > max_val) {
  //         max_val = sum;
  //       }
  //     }
  //   }
  //   return max_val;
  // }
};

int main() {
  std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // std::vector<int> nums{1};
  Solution s1;
  std::cout << s1.maxSubArray(nums);
}
