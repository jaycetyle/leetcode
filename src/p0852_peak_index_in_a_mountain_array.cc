#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int mid = (left + right) / 2;

        while (arr[mid] < arr[mid-1] || arr[mid] < arr[mid+1]) {
            if (arr[mid] < arr[mid-1]) {
                right = mid;
            } else {
                left = mid;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};

TEST(PeakIndexInAMountainArrayTest, test1) {
    vector<int> arr = {0,1,0};
    EXPECT_EQ(Solution().peakIndexInMountainArray(arr), 1);
}

TEST(PeakIndexInAMountainArrayTest, test2) {
    vector<int> arr = {0,2,1,0};
    EXPECT_EQ(Solution().peakIndexInMountainArray(arr), 1);
}

TEST(PeakIndexInAMountainArrayTest, test3) {
    vector<int> arr = {0,10,5,2};
    EXPECT_EQ(Solution().peakIndexInMountainArray(arr), 1);
}
} // namespace
