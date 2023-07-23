#include <gtest/gtest.h>
#include <string>
#include <cctype>

using std::string;

namespace {

class Solution {
public:
    int calculate(string s) {
        _si = 0;
        _s = s;
        return expr();
    }

private:
    std::string peak() {
        while (_s[_si] == ' ') {
            ++_si;
        }
        if (_s[_si] == '(') {
            return "(";
        }
        if (_s[_si] == ')') {
            return ")";
        }
        if (_s[_si] == '-') {
            return "-";
        }
        if (_s[_si] == '+') {
            return "+";
        }
        int begin = _si;
        int end = _si;
        while (isdigit(_s[end])) {
            ++end;
        }
        return _s.substr(begin, end - begin);
    }

    std::string get() {
        std::string ret = peak();
        _si += ret.size();
        return ret;
    }

    // expr = unary ( '+' unary )*
    // expr = unary ( '-' unary )*
    int expr() {
        int result = unary();
        for (string op = peak(); !op.empty(); op = peak()) {
            if (op != "+" && op != "-") {
                break;
            }
            get();
            int rhs = unary();
            if (op == "+") {
                result += rhs;
            } else if (op == "-") {
                result -= rhs;
            }
        }
        return result;
    }

    // unary = '-' paren
    // unary = paren
    int unary() {
        string token = peak();
        if (token == "-") {
            get();
            return -paren();
        } else {
            return paren();
        }
    }

    // paren = '(' expr ')'
    // paren = number
    int paren() {
        string token = peak();
        if (token == "(") {
            get();
            int val = expr();
            get();
            return val;
        } else {
            get();
            return std::stoi(token);
        }
    }

    std::string _s;
    int _si = 0;
};

TEST(BasicCalculator, Test1) {
    Solution s;
    EXPECT_EQ(s.calculate("1 + 1"), 2);
}

TEST(BasicCalculator, Test2) {
    Solution s;
    EXPECT_EQ(s.calculate(" 2-1 + 2 "), 3);
}

TEST(BasicCalculator, Test3) {
    Solution s;
    EXPECT_EQ(s.calculate("(1+(4+5+2)-3)+(6+8)"), 23);
}

} // namespace
