#include <gtest/gtest.h>
#include <string>
#include <vector>

using std::vector;

namespace {

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n + 1);
        for (int i = 0; i <=n; ++i) {
            out[i] = count(i);
        }
        return out;
    }

private:
    int count(int n) {
        int cnt = 0;
        while (n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
};

TEST(P0338, Test) {
    Solution s;

    EXPECT_EQ(vector<int>({0, 1, 1}), s.countBits(2));
    EXPECT_EQ(vector<int>({0, 1, 1, 2, 1, 2}), s.countBits(5));
}
} // namespace
