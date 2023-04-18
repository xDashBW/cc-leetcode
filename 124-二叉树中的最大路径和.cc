#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  std::priority_queue<int> _pri_que;

  int dps(TreeNode *root) {
    if (!root) {
      return 0;
    }


    _pri_que.push(maxload);
  }

  int maxPathSum(TreeNode *root) {
    dps(root);
    return _pri_que.top();
  }
};
