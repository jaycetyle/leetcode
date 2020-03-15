/**
 * Reverse a singly linked list.
 *
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
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

ListNode* reverseList(ListNode* head)
{
	if (!head) {
		return head;
	}

	ListNode* next = head->next;
	head->next = nullptr;
	while (next) {
		ListNode* prev = head;
		head = next;
		next = next->next;
		head->next = prev;
	}

	return head;
}
