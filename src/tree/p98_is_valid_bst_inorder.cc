#include <gtest/gtest.h>

#include "tree_node.h"
#include "p98_is_valid_bst_test_case_factory.h"

class IsValidBSTInorderSolution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    if (root->left) {
      if (root->val <= root->left->val) {
        return false;
      }
      if (!isValidBST(root->left)) {
        return false;
      }
    }
    if (_last != nullptr && root->val <= _last->val) {
      return false;
    }
    _last = root;
    return isValidBST(root->right);
  }

private:
  TreeNode *_last = nullptr;
};

TEST(IsValidBSTInorderTest, test) {
  run_test<IsValidBSTInorderSolution>();
}
