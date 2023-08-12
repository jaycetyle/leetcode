#include <gtest/gtest.h>
#include <vector>

using std::vector;

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

namespace {
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        dfs(output, root, 0);
        return output;
    }

private:
    void dfs(vector<int> &output, TreeNode *root, int level) {
        if (!root) {
            return;
        }

        dfs(output, root->left, level+1);
        if (output.size() <= level) {
            output.resize(level + 1);
        }
        output[level] = root->val;
        dfs(output, root->right, level+1);
    }
};

TEST(BinaryTreeRightSideViewTest, test1) {
    Solution s;
    vector<int> expected = {1, 3, 4};
    EXPECT_EQ(s.rightSideView(
        new TreeNode(1,
            new TreeNode(2,
                nullptr,
                new TreeNode(5)),
            new TreeNode(3,
                nullptr,
                new TreeNode(4)))),
        expected);
}

TEST(BinaryTreeRightSideViewTest, test2) {
    Solution s;
    vector<int> expected = {1, 3};
    EXPECT_EQ(s.rightSideView(
        new TreeNode(1,
            nullptr,
            new TreeNode(3))),
        expected);
}

} // namespace
