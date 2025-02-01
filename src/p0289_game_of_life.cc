#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Board {
public:
    Board(vector<vector<int>>& board)
        : _board(board)
        , kRowSz(board.size())
        , kColSz(board[0].size()) {}

    const int kColSz;
    const int kRowSz;

    int getOrZero(int row, int col) {
        if (row >= kRowSz || row < 0)
            return 0;
        if (col >= kColSz || col < 0)
            return 0;
        return _board[row][col] & 0b1;
    }

    int sumNeighbors(int row, int col) {
        return getOrZero(row - 1, col - 1) +
               getOrZero(row - 1, col) +
               getOrZero(row - 1, col + 1) +
               getOrZero(row, col - 1) +
               getOrZero(row, col + 1) +
               getOrZero(row + 1, col - 1) +
               getOrZero(row + 1, col) +
               getOrZero(row + 1, col + 1);
    }

    void markAlive(int row, int col) {
        _board[row][col] |= 0b10;
    }

    void update() {
        for (int r = 0; r < kRowSz; ++r) {
            for (int c = 0; c < kColSz; ++c) {
                int sum = sumNeighbors(r, c);
                if (_board[r][c]) {
                    // live ceil with two or three live neighbors lives
                    if (sum == 2 || sum == 3)
                        markAlive(r, c);
                } else {
                    // dead ceil with three live neighbors becomes a live cell
                    if (sum == 3)
                        markAlive(r, c);
                }
            }
        }

        for (int r = 0; r < kRowSz; ++r)
            for (int c = 0; c < kColSz; ++c)
                _board[r][c] >>= 1;
    }

private:
    vector<vector<int>>& _board;
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        Board(board).update();
    }
};

TEST(GameOfLifeTest, test1) {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    vector<vector<int>> expected = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    Solution().gameOfLife(board);
    EXPECT_EQ(board, expected);
}

TEST(GameOfLifeTest, test2) {
    vector<vector<int>> board = {{1,1},{1,0}};
    vector<vector<int>> expected = {{1,1},{1,1}};
    Solution().gameOfLife(board);
    EXPECT_EQ(board, expected);
}
} // namespace
