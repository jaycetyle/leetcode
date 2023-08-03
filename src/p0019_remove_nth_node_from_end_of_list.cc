#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;

namespace {
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode root(0, head);
        ListNode *ptr = &root;

        int len = 0;
        while (ptr->next) {
            ptr = ptr->next;
            ++len;
        }

        if (n > len) {
            return head;
        }

        n = len - n + 1;
        ptr = &root;

        for (int i = 1; i < n; ++i) {
            ptr = ptr->next;
        }

        // TODO: free ptr->next
        ptr->next = ptr->next->next;

        return root.next;
    }
};
} // namespace
