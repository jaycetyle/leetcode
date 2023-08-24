#include <gtest/gtest.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;

        int begin = 0;
        int remain = maxWidth - words[begin].size();
        int wordLength = words[begin].size();
        for (int i = 1; i < words.size(); ++i) {
            if (remain >= words[i].size() + 1) {
                remain -= words[i].size() + 1;
                wordLength += words[i].size();
                continue;
            }

            output.emplace_back(createLine(words, begin, i,
                                           wordLength, maxWidth));
            begin = i;
            remain = maxWidth - words[begin].size();
            wordLength = words[begin].size();
        }

        output.emplace_back(maxWidth, ' ');
        int p = 0;
        for (int i = begin; i < words.size(); ++i) {
            memcpy(&output.back()[p], words[i].data(), words[i].size());
            p += words[i].size() + 1;
        }
        return output;
    }

    string createLine(const vector<string>& words, int begin, int end,
                      int wordLength, int maxWidth) {
        string s(maxWidth, ' ');

        int p = 0;
        memcpy(&s[p], words[begin].data(), words[begin].size());
        p += words[begin].size();

        int wordCount = end - begin;
        if (wordCount == 1) {
            s.resize(maxWidth, ' ');
            return s;
        }

        int spaceCount = maxWidth - wordLength;
        int quotient = spaceCount / (wordCount - 1);
        int remainder = spaceCount % (wordCount - 1);

        for (int i = begin + 1; i < end; ++i) {
            p += quotient;
            if (remainder) {
                ++p;
                --remainder;
            }
            memcpy(&s[p], words[i].data(), words[i].size());
            p += words[i].size();
        }
        return s;
    }
};

TEST(TextJustificationTest, test1) {
    Solution s;
    vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> expected{"This    is    an", "example  of text", "justification.  "};
    EXPECT_EQ(s.fullJustify(words, 16), expected);
}

} // namespace
