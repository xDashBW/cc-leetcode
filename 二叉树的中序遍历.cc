#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
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
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> vec;
    TreeNode *iter = root;
    std::stack<TreeNode *> stack;
    while (1) {
      if (iter) {
        stack.push(iter);
        iter = iter->left;
      } else {
        if (stack.empty()) {
          break;
        }
        vec.push_back(stack.top()->val);
        iter = stack.top()->right;
        stack.pop();
      }
    }
    return vec;
  }
};