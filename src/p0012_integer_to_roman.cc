#include <gtest/gtest.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {
class Solution {
public:
    string intToRoman(int num) {
        string output;
        vector<int> numbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for (int i = 0; i < numbers.size(); ++i) {
            if (!num)
                break;

            while (num >= numbers[i]) {
                num -= numbers[i];
                output.append(romans[i]);
            }
        }

        return output;
    }
};

TEST(IntegerToRomanTest, test1) {
    EXPECT_EQ("MMMDCCXLIX", Solution().intToRoman(3749));
    EXPECT_EQ("MCMXCIV", Solution().intToRoman(1994));
    EXPECT_EQ("LVIII", Solution().intToRoman(58));
    EXPECT_EQ("LXIV", Solution().intToRoman(64));
}
} // namespace
