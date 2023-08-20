#include <gtest/gtest.h>
#include <string>
#include <cctype>

namespace {
class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.size() - 1;

        while (j >= i) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            }
            if (!isalnum(s[j])) {
                --j;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

TEST(IsPalinDromeTest, test1) {
    EXPECT_TRUE(Solution().isPalindrome("A man, a plan, a canal: Panama"));
}

TEST(IsPalinDromeTest, test2) {
    EXPECT_FALSE(Solution().isPalindrome("race a car"));
}

TEST(IsPalinDromeTest, test3) {
    EXPECT_TRUE(Solution().isPalindrome(" "));
}
} // namespace
