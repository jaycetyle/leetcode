#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    int hammingWeight(int n) {
        int out = 0;

        while (n) {
            out += n & 1;
            n >>= 1;
        }

        return out;
    }
};

TEST(HammingWeightTest, test1) {
    EXPECT_EQ(3, Solution().hammingWeight(11));
    EXPECT_EQ(1, Solution().hammingWeight(128));
    EXPECT_EQ(30, Solution().hammingWeight(2147483645));
}
} // namespace
