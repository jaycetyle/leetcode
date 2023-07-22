#include <gtest/gtest.h>
#include <vector>
#include <utility>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        for (; k >= 0; --k) {
            if (i >= 0 && j < 0) {
                break;
            }
            if (j >= 0 && i < 0) {
                nums1[k] = nums2[j];
                --j;
            } else if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                --i;
            } else {
                nums1[k] = nums2[j];
                --j;
            }
        }
    }
};


TEST(MergeSortedArrayTest, test1) {
    vector<int> v1{1, 2, 3, 0, 0, 0};
    vector<int> v2{2, 5, 6};
    vector<int> expected{1, 2, 2, 3, 5, 6};

    Solution().merge(v1, 3, v2, 3);
    EXPECT_EQ(expected, v1);
}

TEST(MergeSortedArrayTest, test2) {
    vector<int> v1{1};
    vector<int> v2{};
    vector<int> expected{1};

    Solution().merge(v1, 1, v2, 0);
    EXPECT_EQ(expected, v1);
}

TEST(MergeSortedArrayTest, test3) {
    vector<int> v1{0};
    vector<int> v2{1};
    vector<int> expected{1};

    Solution().merge(v1, 0, v2, 1);
    EXPECT_EQ(expected, v1);
}
