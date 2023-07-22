#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxStep = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxStep) {
                return false;
            }
            maxStep = std::max(maxStep, i + nums[i]);
        }
        return true;
    }
};


TEST(JumpGameTest, test1) {
    vector<int> v{2, 3, 1, 1, 4};

    EXPECT_TRUE(Solution().canJump(v));
}

TEST(JumpGameTest, test2) {
    vector<int> v{3, 2, 1, 0, 4};

    EXPECT_FALSE(Solution().canJump(v));
}
} // namespace
