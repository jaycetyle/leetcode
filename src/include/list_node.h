#pragma once
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode* create(const std::vector<int> values) {
        ListNode head;
        ListNode *p = &head;
        for (int v: values) {
            p->next = new ListNode(v);
            p = p->next;
        }
        return head.next;
    }

    static bool compare(const ListNode *pList, const std::vector<int> values) {
        const ListNode *p = pList;
        for (int v: values) {
            if (!p || v != p->val)
                return false;
            p = p->next;
        }
        return !p;
    }
};
