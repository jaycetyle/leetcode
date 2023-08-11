#include <gtest/gtest.h>
#include <string>
#include <algorithm>

using std::string;

namespace {

class Solution {
public:
    string addBinary(string a, string b) {
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        int sz = std::max(a.size(), b.size());
        int carry = 0;
        string out;
        out.reserve(sz + 1);
        for (int i = 0; i < sz; ++i) {
            int x = (i < a.size() && a[i] == '1');
            int y = (i < b.size() && b[i] == '1');
            int sum = x + y + carry;
            out.push_back('0' + (sum & 1));
            carry = sum >> 1;
        }

        if (carry) {
            out.push_back('1');
        }

        std::reverse(out.begin(), out.end());
        return out;
    }
};


TEST(AddBinaryTest, test1) {
    Solution s;
    EXPECT_EQ(s.addBinary("11", "1"), "100");
}

TEST(AddBinaryTest, test2) {
    Solution s;
    EXPECT_EQ(s.addBinary("1010", "1011"), "10101");
}
} // namespace
