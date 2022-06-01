#include <gtest/gtest.h>

#include <stack>

#include "tree_node.h"
#include "p98_is_valid_bst_test_case_factory.h"

class IsValidBSTStackSolution {
 public:
  bool isValidBST(TreeNode* root) {
    std::stack<TreeNode*> s;
    TreeNode *p = root, *pre = nullptr;

    while (p || !s.empty()) {
      while (p) {
        s.push(p);
        if (p->left && p->val <= p->left->val) {
          return false;
        }
        p = p->left;
      }

      p = s.top();
      s.pop();
      if (pre && p->val <= pre->val) {
        return false;
      }
      pre = p;
      p = p->right;
    }
    return true;
  }
};

TEST(IsValidBSTStackTest, test) {
  run_test<IsValidBSTStackSolution>();
}
