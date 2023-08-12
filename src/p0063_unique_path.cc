#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector<int> dp(m);

        dp[0] = !obstacleGrid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                if (j > 0) {
                    dp[j] += dp[j-1];
                }
            }
        }

        return dp[m-1];
    }
};

TEST(UniquePathTest, test1) {
    vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    EXPECT_EQ(2, Solution().uniquePathsWithObstacles(v));
}

TEST(UniquePathTest, test2) {
    vector<vector<int>> v{{0, 1}, {0, 0}};

    EXPECT_EQ(1, Solution().uniquePathsWithObstacles(v));
}
} // namespace
