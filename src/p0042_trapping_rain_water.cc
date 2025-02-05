#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using std::vector;

namespace {

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        vector<int> left(height.size());
        vector<int> right(height.size());

        int h = height[0];
        left[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] >= h) {
                left[i] = height[i];
                h = height[i];
            } else {
                left[i] = h;
            }
        }

        h = height[height.size() - 1];
        right[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; --i) {
            if (height[i] >= h) {
                right[i] = height[i];
                h = height[i];
            } else {
                right[i] = h;
            }
        }

        h = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            int dam = std::min(left[i], right[i]);
            if (dam > height[i]) {
                h += dam - height[i];
            }
        }

        return h;
    }
};

TEST(TrappingRainWaterTest, case1) {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    EXPECT_EQ(s.trap(height), 6);
}

TEST(TrappingRainWaterTest, case2) {
    Solution s;
    vector<int> height = {4,2,0,3,2,5};
    EXPECT_EQ(s.trap(height), 9);
}

TEST(TrappingRainWaterTest, case3) {
    Solution s;
    vector<int> height = {5,4,1,2};
    EXPECT_EQ(s.trap(height), 1);
}
}  // namespace