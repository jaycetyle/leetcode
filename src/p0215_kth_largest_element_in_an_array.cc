#include <gtest/gtest.h>
#include <vector>

using std::vector;

namespace {

class Heap {
public:
    explicit Heap(vector<int>& nums)
        : _nums(nums)
    {
        for (int i = _nums.size() / 2; i >= 0; --i)
            heapify(i);
    }

    int popMax() {
        int max = _nums[0];

        _nums[0] = _nums.back();
        _nums.pop_back();
        sink(0);

        return max;
    }

private:
    void sink(int i) {
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = l;

            if (l >= _nums.size())
                break;

            if (_nums[r] > _nums[l])
                largest = r;

            if (_nums[largest] > _nums[i])
                std::swap(_nums[largest], _nums[i]);
            i = largest;
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < _nums.size() && _nums[l] > _nums[i])
            largest = l;

        if (r < _nums.size() && _nums[r] > _nums[largest])
            largest = r;

        if (largest != i) {
            std::swap(_nums[i], _nums[largest]);
            heapify(largest);
        }
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    vector<int> &_nums;
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap heap(nums);

        int out = 0;
        for (int i = 0; i < k; ++i)
            out = heap.popMax();

        return out;
    }
};

TEST(FindKthLargestTest, test1) {
    vector<int> nums({3,2,1,5,6,4});
    EXPECT_EQ(5, Solution().findKthLargest(nums, 2));
}

TEST(FindKthLargestTest, test2) {
    vector<int> nums({3,2,3,1,2,4,5,5,6});
    EXPECT_EQ(4, Solution().findKthLargest(nums, 4));
}
} // namespace
