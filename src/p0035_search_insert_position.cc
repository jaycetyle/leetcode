#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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

        return left;
    }
};

TEST(BinarySearch, Test1) {
    Solution s;
    vector<int> nums = {1,3,5,6};
    EXPECT_EQ(s.searchInsert(nums, 5), 2);
}

TEST(BinarySearch, Test2) {
    Solution s;
    vector<int> nums = {1,3,5,6};
    EXPECT_EQ(s.searchInsert(nums, 2), 1);
}

TEST(BinarySearch, Test3) {
    Solution s;
    vector<int> nums = {1,3,5,6};
    EXPECT_EQ(s.searchInsert(nums, 7), 4);
}
} // namespace
