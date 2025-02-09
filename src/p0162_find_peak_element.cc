#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        int peak = (lower + upper) / 2;

        for(; peak != lower || peak != upper; peak = (lower + upper) / 2) {
            if (peak + 1 < nums.size() && nums[peak + 1] > nums[peak]) {
                lower = peak + 1;
                continue;
            }
            if (peak - 1 >= 0 && nums[peak - 1] > nums[peak]) {
                upper = peak;
                continue;
            }
            break;
        }

        return peak;
    }
};

TEST(FindPeakElementTest, test1) {
    vector<int> input({1,2,3,1});
    EXPECT_EQ(2, Solution().findPeakElement(input));
}

TEST(FindPeakElementTest, test2) {
    vector<int> input({1,2,1,3,5,6,4});
    int ans = Solution().findPeakElement(input);
    EXPECT_TRUE(ans == 1 || ans == 5);
}

TEST(FindPeakElementTest, test3) {
    vector<int> input({1});
    EXPECT_EQ(0, Solution().findPeakElement(input));
}

TEST(FindPeakElementTest, test4) {
    vector<int> input({3, 1});
    EXPECT_EQ(0, Solution().findPeakElement(input));
}

TEST(FindPeakElementTest, test5) {
    vector<int> input({3, 1, 3});
    int ans = Solution().findPeakElement(input);
    EXPECT_TRUE(ans == 0 || ans == 2);
}
} // namespace
