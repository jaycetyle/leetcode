#include <gtest/gtest.h>
#include <cmath>
#include <stack>

namespace {

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        std::stack<bool> s;
        int c = n;
        while (c) {
            s.push(c % 2);
            c = c / 2;
        }

        double result = 1;
        while (!s.empty()) {
            result *= result;
            if (s.top()) {
                result *= x;
            }
            s.pop();
        }
        return n > 0 ? result : 1 / result;
    }
};

TEST(MyPowTest, tes2) {
    Solution s;
    EXPECT_DOUBLE_EQ(s.myPow(2.0, 10), std::pow(2.0, 10));
    EXPECT_DOUBLE_EQ(s.myPow(2.1, 3), std::pow(2.1, 3));
    EXPECT_DOUBLE_EQ(s.myPow(2.0, -2), std::pow(2.0, -2));
    EXPECT_DOUBLE_EQ(s.myPow(2.0, -2147483648), std::pow(2.0, -2147483648));
}
} // namespace
