#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

using std::vector;

namespace {
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j < amount + 1; ++j) {
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};

TEST(CoinChangeTest, test1) {
    Solution s;
    vector<int> coins = {1, 2, 5};
    EXPECT_EQ(s.change(5, coins), 4);
}

TEST(CoinChangeTest, test2) {
    Solution s;
    vector<int> coins = {2};
    EXPECT_EQ(s.change(3, coins), 0);
}

TEST(CoinChangeTest, test3) {
    Solution s;
    vector<int> coins = {10};
    EXPECT_EQ(s.change(10, coins), 1);
}
} // namespace
