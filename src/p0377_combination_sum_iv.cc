#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        _cache.resize(target, -1);
        return solve(nums, target);
    }

private:
    int solve(const vector<int>& nums, int remain) {
        if (remain == 0) {
            return 1;
        }
        if (remain < 0) {
            return 0;
        }

        if (_cache[remain - 1] != -1) {
            return _cache[remain - 1];
        }

        int sol = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sol += solve(nums, remain - nums[i]);
        }

        _cache[remain - 1] = sol;
        return sol;
    }

    vector<int> _cache;
};

TEST(CombinationSum4Test, Test) {
    Solution s;
    vector<int> input = {1, 2, 3};
    EXPECT_EQ(7, s.combinationSum4(input, 4));
}
} // namespace
