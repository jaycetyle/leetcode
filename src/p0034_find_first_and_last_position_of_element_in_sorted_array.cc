#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out{-1, -1};

        out[0] = lower(nums, target);
        if (out[0] == -1) {
            return out;
        }
        out[1] = upper(nums, out[0], target);

        return out;
    }

private:
    int lower(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (left >= nums.size() || nums[left] != target) {
            return -1;
        }
        return left;
    }

    int upper(const vector<int>& nums, int left, int target) {
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (left == 0 || nums[left - 1] != target) {
            return -1;
        }
        return left - 1;
    }
};

TEST(SearchRangeTest, test1) {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> expected = {3,4};
    EXPECT_EQ(expected, s.searchRange(nums, target));
}

TEST(SearchRangeTest, test2) {
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    vector<int> expected = {-1,-1};
    EXPECT_EQ(expected, s.searchRange(nums, target));
}

TEST(SearchRangeTest, test3) {
    Solution s;
    vector<int> nums = {};
    int target = 0;
    vector<int> expected = {-1,-1};
    EXPECT_EQ(expected, s.searchRange(nums, target));
}
} // namespace
