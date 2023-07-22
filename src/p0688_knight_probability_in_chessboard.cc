#include <gtest/gtest.h>
#include <map>
#include <tuple>

namespace {

struct Direction {
    Direction(int row, int col)
        : row(row), col(col)
    {}

    int row;
    int col;
};

class Solution {
public:
    // n: size
    // k: steps
    // row: start row
    // column: start column
    double knightProbability(int n, int k, int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n) {
            return 0;
        }

        if (k == 0) {
            return 1;
        }

        std::tuple<int, int, int> key = std::make_tuple(k, row, col);
        if (_cache.find(key) != _cache.end()) {
            return _cache[key];
        }

        double probability = 0;

        probability += knightProbability(n, k - 1, row - 2, col - 1) * 0.125;
        probability += knightProbability(n, k - 1, row - 2, col + 1) * 0.125;
        probability += knightProbability(n, k - 1, row - 1, col - 2) * 0.125;
        probability += knightProbability(n, k - 1, row - 1, col + 2) * 0.125;
        probability += knightProbability(n, k - 1, row + 1, col - 2) * 0.125;
        probability += knightProbability(n, k - 1, row + 1, col + 2) * 0.125;
        probability += knightProbability(n, k - 1, row + 2, col - 1) * 0.125;
        probability += knightProbability(n, k - 1, row + 2, col + 1) * 0.125;

        _cache[key] = probability;
        return probability;
    }

private:
    std::map<std::tuple<int, int, int>, double> _cache;
};


TEST(KnightProbabilityTest, test) {
    EXPECT_EQ(1, Solution().knightProbability(1, 0, 0, 0));
    EXPECT_EQ(0.0625, Solution().knightProbability(3, 2, 0, 0));
}
} // namespace
