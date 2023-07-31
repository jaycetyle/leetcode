#include <gtest/gtest.h>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>

using std::string;

namespace {

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        _cache.resize(s1.size() * s2.size(), -1);
        return solve(s1, s2, 0, 0);
    }

private:
    int solve(const string &s1, const string &s2, int i, int j) {
        if (i >= s1.size()) {
            return sum(s2, j);
        }
        if (j >= s2.size()) {
            return sum(s1, i);
        }

        int key = i + j*s1.size();
        if (_cache[key] != -1) {
            return _cache[key];
        }

        int sol1 = s1[i] + solve(s1, s2, i+1, j);
        int sol2 = s2[j] + solve(s1, s2, i, j+1);
        int sol3 = INT_MAX;
        if (s1[i] == s2[j]) {
            sol3 = solve(s1, s2, i+1, j+1);
        }

        int solMin = std::min({sol1, sol2, sol3});
        _cache[key] = solMin;
        return solMin;
    }

    int sum(const string &s, int i) {
        int total = 0;
        for (; i < s.size(); ++i) {
            total += s[i];
        }
        return total;
    }

    std::vector<int> _cache;
};

TEST(MinimumAsciiDeleteSumForTwoStringsTest, test1) {
    string s1{"sea"};
    string s2{"eat"};

    EXPECT_EQ(231, Solution().minimumDeleteSum(s1, s2));
}

TEST(MinimumAsciiDeleteSumForTwoStringsTest, test2) {
    string s1{"delete"};
    string s2{"leet"};

    EXPECT_EQ(403, Solution().minimumDeleteSum(s1, s2));
}
} // namespace
