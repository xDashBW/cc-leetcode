#include <cmath>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  // level 从 0 开始
  int get(int level) {
    int sum = 0;
    for (; level >= 0; --level) {
      int levelsum = pow(2, level);
      sum += levelsum;
    }
    return sum;
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
  }
};
