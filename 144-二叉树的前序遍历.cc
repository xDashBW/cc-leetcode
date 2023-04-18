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
  void dps(std::vector<int> &vec, TreeNode *node) {
    if (!node) {
      return;
    }
    dps(vec, node->left);
    dps(vec, node->right);
    vec.push_back(node->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> vec;
    dps(vec, root);
    return vec;
  }
};
