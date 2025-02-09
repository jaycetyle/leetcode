#include <gtest/gtest.h>
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

namespace {
class Pair {
public:
    Pair(int a, int b)
        : _a(a)
        , _b(b)
    {}

    int sum() const {
        return _a + _b;
    }

    vector<int> toVector() const {
        return vector<int>({_a, _b});
    }

private:
    int _a;
    int _b;
};

class Compare {
public:
    bool operator()(const Pair &lhs, const Pair &rhs) {
        return lhs.sum() < rhs.sum();
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::priority_queue<Pair, vector<Pair>, Compare> q;
        vector<vector<int>> out(k);

        for (int i = 0; i < nums1.size(); ++i) {
            if (q.size() >= k && nums1[i] + nums2[0] >= q.top().sum())
                break;
            for (int j = 0; j < nums2.size(); ++j) {
                if (q.size() >= k) {
                    if (nums1[i] + nums2[j] >= q.top().sum())
                        break;
                    q.pop();
                }
                q.push(Pair(nums1[i], nums2[j]));
            }
        }

        for (int i = k-1; i >= 0; --i) {
            out[i] = q.top().toVector();
            q.pop();
        }

        return out;
    }
};

TEST(KSmallestPairsTest, test1) {
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    vector<vector<int>> expected = {{1,2},{1,4},{1,6}};
    EXPECT_EQ(expected, Solution().kSmallestPairs(nums1, nums2, 3));
}

TEST(KSmallestPairsTest, test2) {
    vector<int> nums1 = {1,1,2};
    vector<int> nums2 = {1,2,3};
    vector<vector<int>> expected = {{1,1},{1,1}};
    EXPECT_EQ(expected, Solution().kSmallestPairs(nums1, nums2, 2));
}

TEST(KSmallestPairsTest, test3) {
    vector<int> nums1 = {1,2,4,5,6};
    vector<int> nums2 = {3,5,7,9};
    vector<vector<int>> expected = {{1,3},{2,3},{1,5}};
    EXPECT_EQ(expected, Solution().kSmallestPairs(nums1, nums2, 3));
}
} // namespace
