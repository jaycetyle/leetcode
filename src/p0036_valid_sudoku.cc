#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {0};
        bool cols[9][9] = {0};
        bool squares[9][9] = {0};

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.')
                    continue;

                int val = board[row][col] - '1';
                int square = row / 3 * 3 + col / 3;

                if (rows[row][val])
                    return false;
                if (cols[col][val])
                    return false;
                if (squares[square][val])
                    return false;

                rows[row][val] = true;
                cols[col][val] = true;
                squares[square][val] = true;
            }
        }

        return true;
    }
};

TEST(ValidSudokuTest, test1) {
    vector<vector<char>> board =
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};

    EXPECT_TRUE(Solution().isValidSudoku(board));
}

TEST(ValidSudokuTest, test2) {
    vector<vector<char>> board =
    {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};

    EXPECT_FALSE(Solution().isValidSudoku(board));
}

} // namespace
