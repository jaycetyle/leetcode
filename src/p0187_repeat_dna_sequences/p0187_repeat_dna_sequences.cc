#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;

namespace {

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return {};
        }

        std::unordered_set<int> set;
        std::unordered_set<string> out;
        vector<string> result;

        int rollingHash = 0;
        for (int i = 0; i < 10; ++i) {
            int n = hash(s[i]);
            rollingHash = (rollingHash << 2) + n;
        }
        set.insert(rollingHash);

        for (int i = 10; i < s.size(); ++i) {
            int n = hash(s[i]);
            rollingHash = ((rollingHash << 2) & 0xfffff) + n;
            if (set.find(rollingHash) != set.end()) {
                out.insert(s.substr(i - 9, 10));
            } else {
                set.insert(rollingHash);
            }
        }

        for (auto&& s : out) {
            result.emplace_back(std::move(s));
        }

        return result;
    }

private:
    inline int hash(char c) {
        switch (c) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
        throw std::invalid_argument("invalid char");
    }
};

TEST(RepeatedDnaSequencesTest, test1) {
    string s{"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"};
    std::unordered_set<string> expected{"AAAAACCCCC", "CCCCCAAAAA"};

    vector<string> result = Solution().findRepeatedDnaSequences(s);
    EXPECT_EQ(expected.size(), result.size());
    for (auto&& s : result) {
        EXPECT_TRUE(expected.find(s) != expected.end());
    }
}

TEST(RepeatedDnaSequencesTest, test2) {
    string s{"AAAAAAAAAAAAA"};
    vector<string> expected{"AAAAAAAAAA"};

    EXPECT_EQ(expected, Solution().findRepeatedDnaSequences(s));
}
} // namespace
