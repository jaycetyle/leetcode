#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <set>
#include <random>

using std::vector;
using std::map;

namespace {
class Solution {
public:
    Solution(int n, vector<int>& blacklist)
    {
        std::set<int> blacks(blacklist.begin(), blacklist.end());

        int cnt = n - blacklist.size();
        int end = n - 1;
        for (int b: blacks) {
            if (b >= cnt) {
                break;
            }
            while (blacks.find(end) != blacks.end()) {
                --end;
            }
            _swap[b] = end;
            --end;
        }

        std::random_device rd;
        _generator = std::mt19937(rd());
        _dist = std::uniform_int_distribution<int>(0, cnt - 1);
    }

    int pick() {
        int idx = _dist(_generator);
        if (_swap.find(idx) != _swap.end()) {
            return _swap[idx];
        }
        return idx;
    }

private:
    map<int, int> _swap;
    std::mt19937 _generator;
    std::uniform_int_distribution<int> _dist;
};

TEST(RandomPickWithBlackListTest, test1) {
    vector<int> blackList({5, 0, 4});
    Solution s(6, blackList);

    for (int i = 0; i < 100; ++i) {
        EXPECT_NE(0, s.pick());
        EXPECT_NE(4, s.pick());
        EXPECT_NE(5, s.pick());
    }
}
} // namespace
