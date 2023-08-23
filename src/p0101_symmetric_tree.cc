#include <gtest/gtest.h>
#include <cmath>
#include "tree_node.h"

namespace {
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return bfs(root->left, root->right);
    }

    bool bfs(const TreeNode *left, const TreeNode *right) {
        if (!left || !right) {
            return left == right;
        }

        if (left->val != right->val) {
            return false;
        }

        return bfs(left->left, right->right) && bfs(left->right, right->left);
    }
};

TEST(SymmetricTreeTest, test1) {
    Solution s;
    EXPECT_EQ(s.isSymmetric(
            new TreeNode(1,
                new TreeNode(2,
                    new TreeNode(3),
                    new TreeNode(4)),
                new TreeNode(2,
                    new TreeNode(4),
                    new TreeNode(3)))), true);
}

TEST(SymmetricTreeTest, test2) {
    Solution s;
    EXPECT_EQ(s.isSymmetric(
            new TreeNode(1,
                new TreeNode(2,
                    nullptr,
                    new TreeNode(3)),
                new TreeNode(2,
                    nullptr,
                    new TreeNode(3)))), false);
}
} // namespace
