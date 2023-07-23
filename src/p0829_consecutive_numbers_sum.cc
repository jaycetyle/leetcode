#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            int sum = i * (i - 1) / 2;
            if (sum + i > n) {
                break;
            }
            if (((sum + n) % i) == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

TEST(ConsecutiveNumbersSumTest, test1) {
    EXPECT_EQ(2, Solution().consecutiveNumbersSum(5));
}

TEST(ConsecutiveNumbersSumTest, test2) {
    EXPECT_EQ(3, Solution().consecutiveNumbersSum(9));
}

TEST(ConsecutiveNumbersSumTest, test3) {
    EXPECT_EQ(4, Solution().consecutiveNumbersSum(15));
}
} // namespace
