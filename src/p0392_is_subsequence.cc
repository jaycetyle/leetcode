#include <gtest/gtest.h>
#include <string>

using std::string;

namespace {
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool found = false;
            for (; j < t.size(); ++j) {
                if (s[i] == t[j]){
                    ++j;
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};

TEST(IsSubsequenceTest, test1) {
    Solution s;
    EXPECT_EQ(s.isSubsequence("abc", "ahbgdc"), true);
}

TEST(IsSubsequenceTest, test2) {
    Solution s;
    EXPECT_EQ(s.isSubsequence("axc", "ahbgdc"), false);
}

TEST(IsSubsequenceTest, test3) {
    Solution s;
    EXPECT_EQ(s.isSubsequence("", "ahbgdc"), true);
}
} // namespace
