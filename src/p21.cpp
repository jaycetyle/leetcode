/** 
 * Merge two sorted linked listsand return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output : 1->1->2->3->4->4
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	ListNode(int x)
		: val(x)
		, next(nullptr)
	{}

	int val;
	ListNode *next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode head(0);
	ListNode* last = &head;

	while (l1 != nullptr || l2 != nullptr)
	{
		if (!l1) {
			last->next = l2;
			l2 = l2->next;
		}
		else if (!l2) {
			last->next = l1;
			l1 = l1->next;
		}
		else if (l1->val < l2->val) {
			last->next = l1;
			l1 = l1->next;
		}
		else {
			last->next = l2;
			l2 = l2->next;
		}
		last = last->next;
	}

	return head.next;
}
