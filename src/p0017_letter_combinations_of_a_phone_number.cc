#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;

namespace {
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        _ans.clear();
        _keyboard = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        solve("", digits, 0);

        return _ans;
    }

    void solve(const string &sol, const string &digits, int idx) {
        const std::string &chars = _keyboard[digits[idx]];

        if (idx >= digits.size()) {
            _ans.push_back(sol);
        }

        for (char c: chars) {
            string s = sol + c;
            solve(s, digits, idx+1);
        }
    }

    vector<string> _ans;
    std::unordered_map<char, std::string> _keyboard;
};

TEST(LetterCombinationsOfAPhoneNumberTest, test1) {
    string digits{"23"};
    vector<string> expected{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    EXPECT_EQ(expected, Solution().letterCombinations(digits));
}

TEST(LetterCombinationsOfAPhoneNumberTest, test2) {
    string digits{""};
    vector<string> expected{};

    EXPECT_EQ(expected, Solution().letterCombinations(digits));
}
} // namespace
