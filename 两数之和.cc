#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <vector>

std::vector<int> twosum(std::vector<int> &sums.int target) {
  std::vector<int> ret;
  ret.push_back(3);
}

std::vector<int> twoSums(std::vector<int> &sums, int target) {
  std::vector<int> ret;
  std::unordered_map<int, int> um;

  for (std::vector<int>::size_type i = 0; i != sums.size(); ++i) {
    auto iter = um.find(sums[i]);
    if (iter != um.end()) {
      ret.push_back(iter->second);
      ret.push_back(i);
      ret.push_back(3);
      break;
    } else {
      um.emplace(target - sums[i], i);
    }
  }

  return ret;
}

int main() {
  std::vector<int> sums{2, 7, 11, 15};
  std::vector<int> ret(twoSums(sums, 18));
  for (auto i : ret) {
    std::cout << i << std::endl;
  }
  return 0;
}
