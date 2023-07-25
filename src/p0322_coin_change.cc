#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <tuple>

using std::vector;

namespace {
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        _cache.resize(amount + 1, -2);
        return tryChange(coins, amount);
    }

private:
    int tryChange(const vector<int>& coins, int amount) {
        if (!amount) {
            return 0;
        }

        if (amount < 0) {
            return -1;
        }

        if (_cache[amount] != -2) {
            return _cache[amount];
        }

        int minCount = INT_MAX;
        for (int coin: coins) {
            int cnt = tryChange(coins, amount - coin);
            if (cnt < 0) {
                continue;
            }
            minCount = std::min(minCount, cnt + 1);
        }

        if (minCount == INT_MAX) {
            minCount = -1;
        }
        _cache[amount] = minCount;
        return minCount;
    }

    vector<int> _cache; // amount, count
};

TEST(CoinChangeTest, test1) {
    Solution s;
    vector<int> coins = {1, 2, 5};
    EXPECT_EQ(s.coinChange(coins, 11), 3);
}

TEST(CoinChangeTest, test2) {
    Solution s;
    vector<int> coins = {2};
    EXPECT_EQ(s.coinChange(coins, 3), -1);
}

TEST(CoinChangeTest, test3) {
    Solution s;
    vector<int> coins = {474,83,404,3};
    EXPECT_EQ(s.coinChange(coins, 264), 8);
}
} // namespace
