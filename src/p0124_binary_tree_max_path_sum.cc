#include <gtest/gtest.h>
#include <algorithm>
#include <climits>

namespace {
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        traverse(root);
        return _max;
    }

private:
    int traverse(TreeNode* root) {
        int cnt = 1;
        int &curr = root->val;

        int left = 0, right = 0;
        if (root->left) {
            left = traverse(root->left);
        }

        if (root->right) {
            right = traverse(root->right);
        }

        _max = std::max({_max, curr, curr + left, curr + right,
                         curr + left + right});
        return std::max({curr, curr + left, curr + right});
    }

    int _max = INT_MIN;
};

TEST(BinaryTreeMaxPathSumTest, Test1) {
    Solution s;
    EXPECT_EQ(s.maxPathSum(
            new TreeNode(1,
                new TreeNode(2),
                new TreeNode(3))),
        6);
}

TEST(BinaryTreeMaxPathSumTest, Test2) {
    Solution s;
    EXPECT_EQ(s.maxPathSum(
            new TreeNode(-10,
                new TreeNode(9),
                new TreeNode(20,
                    new TreeNode(15), new TreeNode(7)))),
        42);
}

TEST(BinaryTreeMaxPathSumTest, Test3) {
    Solution s;
    EXPECT_EQ(s.maxPathSum(
            new TreeNode(1,
                new TreeNode(-2,
                    new TreeNode(1,
                        new TreeNode(-1),
                        nullptr),
                    new TreeNode(3)),
                new TreeNode(-3,
                    new TreeNode(-2),
                    nullptr))),
        3);
}
} // namespace
