#include <gtest/gtest.h>
#include <string>
#include <cctype>

using std::string;

namespace {
class Solution {
public:
    string toLowerCase(string s) {
        string out;
        out.reserve(s.size());

        for (int i = 0; i < s.size(); ++i) {
            out.push_back(std::tolower(s[i]));
        }
        return out;
    }
};
} // namespace
