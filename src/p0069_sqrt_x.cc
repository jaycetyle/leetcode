#include <gtest/gtest.h>

namespace {
class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long up = x;
        long long sqrt = x / 2 + 1;

        while (true) {
            if (sqrt*sqrt <= x && (sqrt+1)*(sqrt+1) > x)
                break;
            if (sqrt*sqrt < x)
                low = sqrt;
            else
                up = sqrt;
            sqrt = (low + up) / 2;
        }
        return sqrt;
    }
};

TEST(SqrtTest, test1) {
    EXPECT_EQ(2, Solution().mySqrt(4));
    EXPECT_EQ(2, Solution().mySqrt(8));
    EXPECT_EQ(3, Solution().mySqrt(9));
    EXPECT_EQ(3, Solution().mySqrt(15));
}
} // namespace
