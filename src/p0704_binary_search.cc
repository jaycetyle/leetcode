#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

TEST(BinarySearch, Test1) {
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    EXPECT_EQ(s.search(nums, 9), 4);
}

TEST(BinarySearch, Test2) {
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    EXPECT_EQ(s.search(nums, 2), -1);
}
} // namespace
