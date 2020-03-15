/**
 * Given head which is a reference node to a singly-linked list.
 * The value of each node in the linked list is either 0 or 1.
 * The linked list holds the binary representation of a number.
 *
 * Return the decimal value of the number in the linked list.
 *
 * Constraints:
 *  The Linked List is not empty.
 *  Number of nodes will not exceed 30.
 *  Each node's value is either 0 or 1.
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

int getDecimalValue(ListNode* head)
{
	int ret = 0;

	do {
		ret <<= 1;
		ret |= head->val;
		head = head->next;
	} while(head);

	return ret;
}
