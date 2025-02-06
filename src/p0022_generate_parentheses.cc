#include <gtest/gtest.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace {
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        solve(out, "", n, n);
        return out;
    }

    void solve(vector<string> &out, string str, int l, int r) {
        if (l == 0 && r == 0) {
            out.emplace_back(str);
        }

        if (l > 0) {
            solve(out, str + '(', l - 1, r);
        }

        if (r > l) {
            solve(out, str + ')', l, r - 1);
        }
    };
};


TEST(GenerateParenthesisTest, case1) {
    vector<string> expect;

    expect = {"((()))","(()())","(())()","()(())","()()()"};
    EXPECT_EQ(expect, Solution().generateParenthesis(3));

    expect = {"()"};
    EXPECT_EQ(expect, Solution().generateParenthesis(1));
}
} // namespace
