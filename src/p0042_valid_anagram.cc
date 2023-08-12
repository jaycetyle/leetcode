#include <gtest/gtest.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> table('z' - 'a' + 1);

        for (char c: s) {
            ++table[c - 'a'];
        }

        for (char c: t) {
            int idx = c - 'a';
            if (!table[idx]) {
                return false;
            }
            --table[idx];
        }

        return true;
    }
};

TEST(P0042, Test) {
    Solution s;

    EXPECT_EQ(true, s.isAnagram("anagram", "nagaram"));
    EXPECT_EQ(false, s.isAnagram("rat", "car"));
}
} // namespace
