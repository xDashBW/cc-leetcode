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
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (!isBalanced(root->left) || !isBalanced(root->right)) {
      return false;
    }
    return std::abs(deep(root->left) - deep(root->right)) > 1 ? false : true;
  }

  int deep(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    return std::max(deep(node->left), deep(node->right)) + 1;
  }
};