#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v;

        k = k % nums.size();

        for (int i = nums.size() - k; i < nums.size(); ++i) {
            v.push_back(nums[i]);
        }
        for (int i = nums.size() - 1; i >= k; --i) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = v[i];
        }
    }
};

TEST(RotateArrayTest, test1) {
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    vector<int> expected{5, 6, 7, 1, 2, 3, 4};

    Solution().rotate(v, 3);
    EXPECT_EQ(expected, v);
}

TEST(RotateArrayTest, test2) {
    vector<int> v{-1, -100, 3, 99};
    vector<int> expected{3, 99, -1, -100};

    Solution().rotate(v, 2);
    EXPECT_EQ(expected, v);
}

TEST(RotateArrayTest, test3) {
    vector<int> v{1};
    vector<int> expected{1};

    Solution().rotate(v, 0);
    EXPECT_EQ(expected, v);
}

TEST(RotateArrayTest, test4) {
    vector<int> v{-1};
    vector<int> expected{-1};

    Solution().rotate(v, 2);
    EXPECT_EQ(expected, v);
}
} // namespace
