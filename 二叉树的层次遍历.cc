#include <math.h>

#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::queue<TreeNode *> mque;
    std::vector<std::vector<int>> ret;
    mque.push(root);

    int i = 0;
    int levelsz = 0;
    while (1) {
      TreeNode *first = mque.front();
      ++i;

      if (first) {
        if (i > levelsz) {
          ret.resize(ret.size() + 1);
          levelsz = pow(ret.size(), 2);
        }
        ret[ret.size()].push_back(first->val);
        mque.push(first->left);
        mque.push(first->right);
      } else if (first == nullptr && mque.empty()) {
        break;
      }

      mque.pop();
    }
    return ret;
  }
};
