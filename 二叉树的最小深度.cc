#include <algorithm>
#include <cmath>
#include <vector>

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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    if (!root->left && !root->right) {
      return 1;
    }

    int minv = 10000;
    if (root->left) {
      minv = std::min(minDepth(root->left), minv);
    }
    if (root->right) {
      minv = std::min(minDepth(root->right), minv);
    }

    return minv + 1;
  }
};