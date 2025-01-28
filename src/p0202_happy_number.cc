#include <gtest/gtest.h>

namespace {

class Solution {
public:
    int sqrtSumDigits(int n) {
        int result = 0;

        while (n) {
            int rem = n % 10;
            result += rem * rem;
            n /= 10;
        }

        return result;
    }

    bool isHappy(int n) {
        bool table[1000] = {0};

        while (true) {
            n = sqrtSumDigits(n);
            if (1 == n)
                return true;
            if (table[n])
                return false;
            table[n] = true;
        };
        return false;
    }
};

TEST(HappyNumberTest, test1) {
    EXPECT_TRUE(Solution().isHappy(19));
    EXPECT_FALSE(Solution().isHappy(2));
    EXPECT_FALSE(Solution().isHappy(3));
}
} // namespace
