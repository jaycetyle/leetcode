#include <gtest/gtest.h>
#include <string>

using std::string;

namespace {

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s.substr(1, s.size()-1) + s.substr(0, s.size()-1);
        if (t.find(s) != -1)
            return true;
        return false;

    }
};

TEST(RepeatedSubstringPatternTest, Test) {
    Solution s;

    EXPECT_TRUE(s.repeatedSubstringPattern("abab"));
    EXPECT_FALSE(s.repeatedSubstringPattern("aba"));
    EXPECT_TRUE(s.repeatedSubstringPattern("abcabcabcabc"));
    EXPECT_FALSE(s.repeatedSubstringPattern("a"));
    EXPECT_TRUE(s.repeatedSubstringPattern("ababab"));
}
} // namespace
