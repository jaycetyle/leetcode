/**
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
	ListNode* next;
};

ListNode* removeElements(ListNode* head, int val)
{
	ListNode dummy(0);
	ListNode* last = &dummy;

	while (head) {
		if (head->val != val) {
			last->next = head;
			last = last->next;
		}
		head = head->next;
	}
	last->next = nullptr;
	return dummy.next;
}
