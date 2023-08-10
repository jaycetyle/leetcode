#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int m = (s + e) / 2;

        while (nums[m] != target && nums[e] != target) {
            if (s > m || e == m) {
                return false;
            }
            if (nums[m] > nums[s]) {
                if (target < nums[m] && target >= nums[s]) {
                    e = m;
                    m = (s + m) / 2;
                } else {
                    s = m + 1;
                    m = (e + m) / 2;
                }
            } else if (nums[e] > nums[m]) {
                if (target > nums[m] && target <= nums[e]) {
                    s = m + 1;
                    m = (e + m) / 2;
                } else {
                    e = m;
                    m = (s + m) / 2;
                }
            } else {
                e--;
                m = (e + s) / 2;
            }
        }

        return true;
    }
};

TEST(SearchInRotatedArrayIITest, test1) {
    vector<int> v{2, 5, 6, 0, 0, 1, 1};
    EXPECT_TRUE(Solution().search(v, 2));
}

TEST(SearchInRotatedArrayIITest, test2) {
    vector<int> v{2, 5, 6, 0, 0, 1, 2};
    EXPECT_FALSE(Solution().search(v, 3));
}

TEST(SearchInRotatedArrayIITest, test3) {
    vector<int> v{1, 0, 1, 1, 1};
    EXPECT_TRUE(Solution().search(v, 0));
}
} // namespace
