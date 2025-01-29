#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using std::vector;

namespace {

class Solution {
public:
    bool isOverlap(const vector<int> &a, const vector<int> &b) {
        if (a[1] < b[0])
            return false;
        if (a[0] > b[1])
            return false;
        return true;
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        if (intervals.empty())
            return output;

        std::sort(intervals.begin(), intervals.end());
        output.push_back(intervals.front());

        for (auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            vector<int> &back = output.back();

            if (!isOverlap(back, *it)) {
                output.push_back(*it);
                continue;
            }

            back[0] = std::min(back[0], (*it)[0]);
            back[1] = std::max(back[1], (*it)[1]);
        }

        return output;
    }
};

TEST(MergeIntervalsTest, test1) {
    vector<vector<int>> input{{15,18}, {1,3}, {2,6}, {8,10}};
    vector<vector<int>> expect{{1,6}, {8,10}, {15,18}};

    EXPECT_EQ(expect, Solution().merge(input));
}

TEST(MergeIntervalsTest, test2) {
    vector<vector<int>> input{{1,4}, {4,5}};
    vector<vector<int>> expect{{1,5}};

    EXPECT_EQ(expect, Solution().merge(input));
}

TEST(MergeIntervalsTest, test3) {
    vector<vector<int>> input{{1,4}, {0,3}};
    vector<vector<int>> expect{{0,4}};

    EXPECT_EQ(expect, Solution().merge(input));
}
} // namespace
