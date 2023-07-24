#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <tuple>
#include <cmath>

using std::vector;

namespace {
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        _cache.clear();
        int result = getMaxTotalHeight(rods, 0, 0) / 2;
        return result < 0 ? 0 : result;
    }

private:
    int getMaxTotalHeight(const vector<int> &rods, int idx, int hDiff) {
        int height = rods[idx];
        if (idx == rods.size() - 1) {
            // the last one
            if (hDiff == 0) {
                return 0;
            } else if (height == std::abs(hDiff)) {
                return height;
            }
            return INT32_MIN;
        }

        auto key = std::make_tuple(idx, hDiff);
        if (_cache.find(key) != _cache.end()) {
            return _cache[key];
        }

        // don't choose this rod
        int opt1 = getMaxTotalHeight(rods, idx + 1, hDiff);
        // choose this rod as the first support
        int opt2 = height + getMaxTotalHeight(rods, idx + 1, hDiff + height);
        // choose this rod as the second support
        int opt3 = height + getMaxTotalHeight(rods, idx + 1, hDiff - height);

        int maxSum = std::max({opt1, opt2, opt3});
        _cache[key] = maxSum;
        return maxSum;
    }

    std::map<std::tuple<int, int>, int> _cache;
};

TEST(TallestBillboardTest, test1) {
    vector<int> rods = {1, 2, 3, 6};
    EXPECT_EQ(6, Solution().tallestBillboard(rods));
}

TEST(TallestBillboardTest, test2) {
    vector<int> rods = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(10, Solution().tallestBillboard(rods));
}

TEST(TallestBillboardTest, test3) {
    vector<int> rods = {1, 2};
    EXPECT_EQ(0, Solution().tallestBillboard(rods));
}
} // namespace
