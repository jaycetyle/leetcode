#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n - 1; ++i) {
            if (!isToeplitzMatrix(matrix, 0, i)) {
                return false;
            }
        }

        for (int i = 1; i < m - 1; ++i) {
            if (!isToeplitzMatrix(matrix, i, 0)) {
                return false;
            }
        }

        return true;
    }

private:
    bool isToeplitzMatrix(vector<vector<int>>& matrix, int x, int y) {
        int c = matrix[x][y];
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i + x < m && i + y < n; ++i) {
            if (c != matrix[i + x][i + y]) {
                return false;
            }
        }

        return true;
    }
};

} // namespace
