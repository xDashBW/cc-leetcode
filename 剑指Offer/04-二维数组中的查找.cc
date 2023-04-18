
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    auto n = matrix.size();
    if (n == 0) {
      return false;
    }
    auto m = matrix[0].size();
    bool isfind = false;

    for (decltype(n) i = 0; i < n; ++i) {
      for (decltype(m) j = 0; j < m; ++j) {
        if (matrix[i][j] == target) {
          isfind = true;
          break;
        } else if (target > matrix[i][j]) {
          m = j;
        }
      }
    }
    return isfind;
  }
};