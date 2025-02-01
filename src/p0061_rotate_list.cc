#include <gtest/gtest.h>
#include "list_node.h"

namespace {
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int nodeCount = 0;
        ListNode *p;
        ListNode *tail;

        if (!head)
            return nullptr;

        for (p = head; p; p = p->next) {
            ++nodeCount;
            tail = p;
        }

        k = k % nodeCount;
        if (!k)
            return head;

        p = head;
        for (int i = 0; i < nodeCount - k - 1; ++i)
            p = p->next;

        tail->next = head;
        head = p->next;
        p->next = nullptr;

        return head;
    }
};

TEST(RotateListTest, test1) {
    ListNode *list = ListNode::create({1,2,3,4,5});
    ListNode *output = Solution().rotateRight(list, 2);

    EXPECT_TRUE(ListNode::compare(output, {4,5,1,2,3}));
}

TEST(RotateListTest, test2) {
    ListNode *list = ListNode::create({0,1,2});
    ListNode *output = Solution().rotateRight(list, 4);

    EXPECT_TRUE(ListNode::compare(output, {2,0,1}));
}
} // namespace
