#include <gtest/gtest.h>

using std::vector;

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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        _cache.resize(n/2, {});
        return solve(n);
    }

private:
    vector<TreeNode*> solve(int n) {
        if (n == 1) {
            return { new TreeNode() };
        }

        if (_cache[n/2].size()) {
            return _cache[n];
        }

        vector<TreeNode*> ans;

        for (int left = 1; left < n; left += 2) {
            int right = n - left - 1;
            vector<TreeNode*> leftAns = solve(left);
            vector<TreeNode*> rightAns = solve(right);
            for (TreeNode *leftNode: leftAns) {
                for (TreeNode *rightNode: rightAns) {
                    ans.push_back(new TreeNode(0, leftNode, rightNode));
                }
            }
        }

        _cache[n/2] = ans;
        return ans;
    }

    vector<vector<TreeNode*>> _cache;
};
} // namespace
