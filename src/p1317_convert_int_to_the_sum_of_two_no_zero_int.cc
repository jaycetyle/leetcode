#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
bool isNonZeroInt(int x) {
    while (x >= 10) {
        if (!(x % 10)) {
            return false;
        }
        x /= 10;
    }
    return true;
}

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; ++i) {
            if (isNonZeroInt(i) && isNonZeroInt(n-i)) {
                return {i, n-i};
            }
        }
        return {};
    }
};

TEST(TallestBillboardTest, test1) {
    vector<int> output = Solution().getNoZeroIntegers(2);
    ASSERT_EQ(output.size(), 2);
    EXPECT_TRUE(isNonZeroInt(output[0]));
    EXPECT_TRUE(isNonZeroInt(output[1]));
    EXPECT_EQ(output[0] + output[1], 2);
}

TEST(TallestBillboardTest, test2) {
    vector<int> output = Solution().getNoZeroIntegers(11);
    ASSERT_EQ(output.size(), 2);
    EXPECT_TRUE(isNonZeroInt(output[0]));
    EXPECT_TRUE(isNonZeroInt(output[1]));
    EXPECT_EQ(output[0] + output[1], 11);
}
} // namespace
