#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <set>

using std::string;
using std::unordered_map;
using std::set;

namespace {

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> table;
        set<char> mapped;

        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (table.count(c1)) {
                if (table[c1] != c2)
                    return false;
                continue;
            }
            if (mapped.count(c2))
                return false;
            table[c1] = c2;
            mapped.insert(c2);
        }

        return true;
    }
};

TEST(IsomorphicStringsTest, test1) {
    Solution s;
    EXPECT_TRUE(s.isIsomorphic("egg", "add"));
}

TEST(IsomorphicStringsTest, test2) {
    Solution s;
    EXPECT_FALSE(s.isIsomorphic("foo", "bar"));
}

TEST(IsomorphicStringsTest, test3) {
    Solution s;
    EXPECT_TRUE(s.isIsomorphic("paper", "title"));
}
} // namespace
