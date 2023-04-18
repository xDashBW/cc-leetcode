#include <algorithm>
#include <functional>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int binary_search(std::vector<int>& vec, int left, int right, int pivot) {
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (pivot < vec[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  TreeNode* dps(std::vector<int>& preorder, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[left]);
    int mid = binary_search(preorder, left + 1, right, root->val);
    root->left = dps(preorder, left + 1, mid - 1);
    root->right = dps(preorder, mid, right);
    return root;
  }

  TreeNode* bstFromPreorder(std::vector<int>& preorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    return dps(preorder, 0, preorder.size() - 1);
  }
};
