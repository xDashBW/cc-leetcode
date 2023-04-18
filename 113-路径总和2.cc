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
  void dps(TreeNode *node, int target, std::vector<int> *vec,
           std::vector<std::vector<int>> *sums) {
    if (!node) {
      return;
    }

    vec->push_back(node->val);

    if (!node->left && !node->right) {
      if (node->val == target) {
        sums->push_back(*vec);
        return;
      }
    }

    dps(node->left, target - node->val, vec, sums);
    if (node->left) {
      vec->pop_back();
    }
    dps(node->right, target - node->val, vec, sums);
    if (node->right) {
      vec->pop_back();
    }
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<std::vector<int>> sums;
    std::vector<int> ret;
    dps(root, targetSum, &ret, &sums);
    return sums;
  }
};
