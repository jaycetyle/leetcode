#include <gtest/gtest.h>
#include <vector>
#include <cmath>

using std::vector;

namespace {
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums.front();
        int sum = 0;

        for (int i: nums) {
            if (i > maxSum)
                maxSum = i;

            if (i > 0) {
                sum += i;
                maxSum = std::max(sum, maxSum);
            } else if (sum + i > 0) {
                sum += i;
            } else {
                sum = 0;
            }
        }

        return maxSum;
    }
};

TEST(MaxSubArrayTest, case1) {
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    EXPECT_EQ(6, Solution().maxSubArray(input));
}

TEST(MaxSubArrayTest, case2) {
    vector<int> input = {1};
    EXPECT_EQ(1, Solution().maxSubArray(input));
}

TEST(MaxSubArrayTest, case3) {
    vector<int> input = {-3,-2,0};
    EXPECT_EQ(0, Solution().maxSubArray(input));
}
}  // namespace
