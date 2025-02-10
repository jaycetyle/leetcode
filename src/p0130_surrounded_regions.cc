#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')
                keep(board, i, 0, m, n);
            if (board[i][n-1] == 'O')
                keep(board, i, n-1, m, n);
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O')
                keep(board, 0, j, m, n);
            if (board[m-1][j] == 'O')
                keep(board, m-1, j, m, n);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'K')
                    board[i][j] = 'O';
            }
        }
    }

    void keep(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (board[i][j] == 'X' || board[i][j] == 'K')
            return;

        board[i][j] = 'K';
        keep(board, i - 1, j, m, n);
        keep(board, i, j - 1, m, n);
        keep(board, i + 1, j, m, n);
        keep(board, i, j + 1, m, n);
    }
};
} // namespace
