#include <gtest/gtest.h>

#include <stack>
#include <cstdint>
#include <limits>

#include "tree_node.h"
#include "p98_is_valid_bst_test_case_factory.h"

class IsValidBSTLowHighSolution {
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBst(root, std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
  }

 private:
  bool isValidBst(TreeNode *root, int64_t low, int64_t high) {
    if (root == nullptr) {
        return true;
    }
    if (root->val >= high || root->val <= low) {
        return false;
    }
    return isValidBst(root->left, low, root->val) && isValidBst(root->right, root->val, high);
  }
};

TEST(IsValidBSTLowHighTest, test) {
  run_test<IsValidBSTLowHighSolution>();
}
