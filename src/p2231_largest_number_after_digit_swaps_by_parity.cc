#include <gtest/gtest.h>
#include <utility>

namespace {
class Solution {
public:
    int largestInteger(int num) {
        char digits[10];
        int order;
        long long power = 1;

        for (order = 0; num; ++order) {
            digits[order] = num % 10;
            num /= 10;
        }

        // bubble sort
        for (int i = 0; i < order; ++i) {
            int lastMax[2] = {-1, -1};
            for (int j = 0; j < order - i; ++j) {
                int &last = lastMax[digits[j] & 1];
                if (last < 0) {
                    last = j;
                    continue;
                }
                if (digits[last] > digits[j]) {
                    std::swap(digits[last], digits[j]);
                }
                last = j;
            }
        }

        for (int i = 0; i < order; ++i) {
            num += digits[i] * power;
            power *= 10;
        }

        return num;
    }
};

TEST(SolutionTest, test) {
    Solution solution;
    EXPECT_EQ(solution.largestInteger(65875), 87655);
    EXPECT_EQ(solution.largestInteger(1234), 3412);
    EXPECT_EQ(solution.largestInteger(1000000000), 1000000000);
}


} // namespace
