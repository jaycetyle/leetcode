#include <gtest/gtest.h>

namespace {

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return n;
        }

        int n_2 = 1;
        int n_1 = 2;
        int out = 2;
        for (int i = 3; i <= n; ++i) {
            out = n_1 + n_2;
            n_2 = n_1;
            n_1 = out;
        }
        return out;
    }
};

TEST(ClimbStairsTest, test1) {
    Solution s;
    EXPECT_EQ(s.climbStairs(2), 2);
}

TEST(ClimbStairsTest, test2) {
    Solution s;
    EXPECT_EQ(s.climbStairs(3), 3);
}
} // namespace
