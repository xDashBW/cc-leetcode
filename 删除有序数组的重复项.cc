#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int> &nums) {
    int save = 0;
    auto sum = nums.size();
    decltype(sum) ret = 0;
    decltype(sum) i = 0;

    for (; i < sum; ++i) {
      if (i == 0) {
        save = nums[i];
        continue;
      }

      if (nums[i] == save) {
        auto j = i;
        auto k = i;
        while (nums[j] == save) {
          ++j;
        }
        auto fff = j - k;
        //   i
        // 1 1 1 1 2
        //   k
        //         j
        //         l
        for (auto l = j; l < sum; ++l) {
          nums[k++] = nums[j++];
        }
        sum -= fff;
        save = nums[i];
      } else {
        save = nums[i];
      }
    }
    return i;
  }
};

int main() {
  std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution s1;
  int i = s1.removeDuplicates(nums);
  std::cout << i << std::endl;
  return 0;
}
