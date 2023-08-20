#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include <climits>
#include "tree_node.h"

using std::vector;

namespace {

class Solution {
    static const int kEmpty = INT_MAX;

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> output;
        std::stack<TreeNode*> s1, s2;
        pushAllLeft(s1, root1);
        pushAllLeft(s2, root2);

        while (s1.size() || s2.size()) {
            if (peek(s1) == kEmpty) {
                output.push_back(pop(s2));
            } else if (peek(s2) == kEmpty) {
                output.push_back(pop(s1));
            } else if (peek(s1) <= peek(s2)) {
                output.push_back(pop(s1));
            } else {
                output.push_back(pop(s2));
            }
        }

        return output;
    }

private:
    void pushAllLeft(std::stack<TreeNode*> &s, TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    int peek(std::stack<TreeNode*> &s) {
        if (s.size()) {
            return s.top()->val;
        }
        return kEmpty;
    }

    int pop(std::stack<TreeNode*> &s) {
        if (!s.size()) {
            return kEmpty;
        }
        TreeNode *top = s.top();
        s.pop();
        pushAllLeft(s, top->right);
        return top->val;
    }
};

TEST(AllElementsInTwoBinarySearchTreesTest, test1) {
    Solution s;
    vector<int> expected = {0, 1, 1, 2, 3, 4};
    EXPECT_EQ(s.getAllElements(
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(4)),
        new TreeNode(1,
            new TreeNode(0),
            new TreeNode(3))),
        expected);
}

TEST(AllElementsInTwoBinarySearchTreesTest, test2) {
    Solution s;
    vector<int> expected = {1, 1, 8, 8};
    EXPECT_EQ(s.getAllElements(
        new TreeNode(1,
            nullptr,
            new TreeNode(8)),
        new TreeNode(8,
            new TreeNode(1),
            nullptr)),
        expected);
}
} // namespace
