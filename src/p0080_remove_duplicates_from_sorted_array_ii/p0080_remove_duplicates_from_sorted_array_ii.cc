#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int count = 1;

        if (nums.size() <= 1) {
            return nums.size();
        }

        for (; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                ++i;
                count = 1;
                nums[i] = nums[j];
            } else if (nums[i] == nums[j] && count < 2) {
                ++i;
                ++count;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

TEST(RemoveDuplicatesTest, test1) {
    vector<int> v{1, 1, 1, 2, 2, 3};
    vector<int> expected{1, 1, 2, 2, 3};

    EXPECT_EQ(5, Solution().removeDuplicates(v));
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(expected[i], v[i]);
    }
}

TEST(RemoveDuplicatesTest, test2) {
    vector<int> v{0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> expected{0, 0, 1, 1, 2, 3, 3};

    EXPECT_EQ(7, Solution().removeDuplicates(v));
    for (int i = 0; i < 7; ++i) {
        EXPECT_EQ(expected[i], v[i]);
    }
}
} // namespace
