#include <gtest/gtest.h>
#include <vector>
#include "tree_node.h"

using std::vector;

namespace {
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }

    TreeNode *solve(vector<int>& nums, size_t begin, size_t end) {
        if (begin == end)
            return NULL;
        size_t mid = (end + begin) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, begin, mid);
        root->right = solve(nums, mid + 1, end);
        return root;
    }
};

} // namespace
