#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

namespace {
class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> cache(
            stones.size(), vector<int>(stones.size(), -1));
        return solve(cache, stones, 0, 0);
    }

private:
    bool solve(vector<vector<int>> &cache,
               vector<int>& stones, int i, int lastJump) {
        if (i >= stones.size()) {
            return false;
        }

        if (i == stones.size() - 1) {
            return true;
        }

        if (cache[i][lastJump] != -1) {
            return cache[i][lastJump];
        }

        int ans = false;
        for (int j = lastJump - 1; j <= lastJump + 1; ++j) {
            if (!j) {
                continue;
            }
            int loc = stones[i] + j;
            auto it = std::lower_bound(stones.begin() + i, stones.end(), loc);
            if (it == stones.end() || *it != loc) {
                continue;
            }
            int idx = it - stones.begin();
            ans = ans || solve(cache, stones, idx, j);
        }

        cache[i][lastJump] = ans;
        return ans;
    }
};

TEST(FrogJumpTest, test1) {
    Solution s;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    EXPECT_TRUE(s.canCross(stones));
}

TEST(FrogJumpTest, test2) {
    Solution s;
    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
    EXPECT_FALSE(s.canCross(stones));
}

TEST(FrogJumpTest, test3) {
    Solution s;
    vector<int> stones = {0,1,2,3,4,5,6,7,8,9,10,99999999};
    EXPECT_FALSE(s.canCross(stones));
}

TEST(FrogJumpTest, test4) {
    Solution s;
    vector<int> stones = {0,2};
    EXPECT_FALSE(s.canCross(stones));
}
} // namespace
