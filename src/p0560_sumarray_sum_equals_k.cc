#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <numeric>

using std::vector;

namespace {
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int out = 0;
        std::unordered_map<int, int> cache;

        vector<int> preSum(nums.size(), 0);
        std::partial_sum(nums.begin(), nums.end(), preSum.begin());
        cache[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            int remain = preSum[i] - k;
            if (cache.count(remain)) {
                out += cache[remain];
            }
            if (cache.count(preSum[i])) {
                ++cache[preSum[i]];
            } else {
                cache[preSum[i]] = 1;
            }
        }
        return out;
    }
};

TEST(SummArraySumEqualsKTest, test1) {
    vector<int> array = {1, 1, 1};
    EXPECT_EQ(3, Solution().subarraySum(array, 1));
    EXPECT_EQ(2, Solution().subarraySum(array, 2));
    EXPECT_EQ(1, Solution().subarraySum(array, 3));
}

TEST(SummArraySumEqualsKTest, test2) {
    vector<int> array = {1, 2, 3};
    EXPECT_EQ(2, Solution().subarraySum(array, 3));
    EXPECT_EQ(1, Solution().subarraySum(array, 5));
}

TEST(SummArraySumEqualsKTest, test3) {
    vector<int> array = {1, -1, 0};
    EXPECT_EQ(3, Solution().subarraySum(array, 0));
}
} // namespace
