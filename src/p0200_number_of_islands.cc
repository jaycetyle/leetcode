#include <gtest/gtest.h>
#include <vector>
#include <set>

using std::vector;
using std::set;

namespace {
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    markIslands(grid, i , j);
                    ++count;
                }
            }
        }
        return count;
    }

    void markIslands(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        if (grid[i][j] != '1')
            return;
        grid[i][j] = 'M';
        markIslands(grid, i - 1, j);
        markIslands(grid, i + 1, j);
        markIslands(grid, i, j - 1);
        markIslands(grid, i, j + 1);
    }
};

TEST(NumIslandsTest, test1) {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    EXPECT_EQ(1, Solution().numIslands(grid));
}

TEST(NumIslandsTest, test2) {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    EXPECT_EQ(3, Solution().numIslands(grid));
}

TEST(NumIslandsTest, test3) {
    vector<vector<char>> grid = {
        {'1','0','1','0','0'},
        {'1','1','1','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    EXPECT_EQ(2, Solution().numIslands(grid));
}
} // namespace
