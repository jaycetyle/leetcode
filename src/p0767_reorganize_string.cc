#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <functional>
#include <set>

using std::string;
using std::vector;
using std::set;

namespace {
class Solution {
public:
    string reorganizeString(string s) {
        if (s.empty()) {
            return "";
        }

        vector<int> counter(26, 0);
        string out;
        out.reserve(s.size());

        for (char c: s) {
            ++counter[c - 'a'];
        }

        auto table = set<char, std::function<bool(const int&, const int&)>> {
            [&counter](const int &a, const int &b) {
                return counter[a] >= counter[b];
            }
        };

        for (int i = 0; i < counter.size(); ++i) {
            if (!counter[i]) {
                continue;
            }
            table.insert(i);
        }

        while (out.size() != s.size()) {
            for (auto it = table.begin(); it != table.end(); ++it) {
                char c = *it + 'a';
                int i = *it;
                if (out.size() && c == out.back()) {
                    continue;
                }
                out.push_back(c);
                --counter[i];
                table.erase(it);
                if (counter[i]) {
                    table.insert(i);
                }
                break;
            }

            if (table.size() == 1 && *table.begin() + 'a' == out.back()) {
                return "";
            }
        }

        return out;
    }
};

TEST(reorganizeStringTest, test1) {
    Solution s;

    EXPECT_EQ("aba", s.reorganizeString("aab"));
    EXPECT_EQ("", s.reorganizeString("aaab"));
}
} // namespace
