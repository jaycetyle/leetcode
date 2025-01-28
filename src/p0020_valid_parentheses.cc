#include <gtest/gtest.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace {

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        for (auto c: s) {
            switch (c) {
            case '(':
                stack.push_back(')');
                break;
            case '[':
                stack.push_back(']');
                break;
            case '{':
                stack.push_back('}');
                break;

            case ')':
            case ']':
            case '}':
                if (stack.empty())
                    return false;
                if (stack.back() != c)
                    return false;
                stack.pop_back();
                break;
            }
        }

        return stack.empty();
    }
};

TEST(ValidParenthesesTest, test1) {
    EXPECT_TRUE(Solution().isValid("()"));
    EXPECT_TRUE(Solution().isValid("()[]{}"));
    EXPECT_FALSE(Solution().isValid("(]"));
    EXPECT_TRUE(Solution().isValid("([])"));
    EXPECT_FALSE(Solution().isValid("("));
    EXPECT_FALSE(Solution().isValid("())"));
    EXPECT_FALSE(Solution().isValid("([{]})"));
}

} // namespace
