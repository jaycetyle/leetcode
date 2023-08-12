#include <gtest/gtest.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace {

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board[0].size();
        int n = board.size();
        vector<vector<bool>> path(n, vector<bool>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // search the first letter
                if (board[i][j] == word[0]) {
                    if (dfs(path, board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<bool>> &path,
             const vector<vector<char>>& board,
             int i, int j,
             const string &word, int idx) {
        if (i < 0 || j < 0
                || i >= board.size() || j >= board[0].size()
                || idx >= word.size() || path[i][j]) {
            return false;
        }
        if (idx + 1 == word.size()) {
            return word[idx] == board[i][j];
        }
        if (word[idx] != board[i][j]) {
            return false;
        }

        bool success = false;
        path[i][j] = true;
        if (dfs(path, board, i+1, j, word, idx+1)) {
            success = true;
        } else if (dfs(path, board, i, j+1, word, idx+1)) {
            success = true;
        } else if (dfs(path, board, i-1, j, word, idx+1)) {
            success = true;
        } else if (dfs(path, board, i, j-1, word, idx+1)) {
            success = true;
        }
        path[i][j] = false;
        return success;
    }
};

TEST(WordSearchTest, test1) {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    EXPECT_TRUE(s.exist(board, "ABCCED"));
}

TEST(WordSearchTest, test2) {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    EXPECT_TRUE(s.exist(board, "SEE"));
}

TEST(WordSearchTest, test3) {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    EXPECT_FALSE(s.exist(board, "ABCB"));
}
} // namespace
