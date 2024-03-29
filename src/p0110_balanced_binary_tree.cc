#include <gtest/gtest.h>
#include <cmath>
#include "tree_node.h"

namespace {
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }

private:
    bool dfs(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }

        int l = 0, r = 0;
        if (!dfs(root->left, l)) {
            return false;
        }

        if (!dfs(root->right, r)) {
            return false;
        }

        height = std::max(l, r) + 1;
        return std::abs(l - r) <= 1;
    }
};

TEST(BalancedBinaryTreeTest, Test1) {
    Solution s;
    EXPECT_EQ(s.isBalanced(
            new TreeNode(3,
                new TreeNode(9),
                new TreeNode(20,
                    new TreeNode(15), new TreeNode(7)))), true);
}

TEST(BalancedBinaryTreeTest, Test2) {
    Solution s;
    EXPECT_EQ(s.isBalanced(
        new TreeNode(1,
            new TreeNode(2,
                new TreeNode(3,
                    new TreeNode(4),
                    new TreeNode(4)),
                new TreeNode(3)),
            new TreeNode(2))), false);
}
} // namespace
