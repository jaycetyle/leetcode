#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                --k;
            }
            if (k == 0) {
                return i;
            }
        }
        return -1;
    }
};

TEST(KthFactorTest, test1) {
    EXPECT_EQ(3, Solution().kthFactor(12, 3));
}

TEST(KthFactorTest, test2) {
    EXPECT_EQ(7, Solution().kthFactor(7, 2));
}

TEST(KthFactorTest, test3) {
    EXPECT_EQ(-1, Solution().kthFactor(4, 4));
}
} // namespace
