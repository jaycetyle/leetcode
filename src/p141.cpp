/**
 * Given a linked list, determine if it has a cycle in it.
 *
 * Can you solve it using O(1) (i.e. constant) memory?
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

bool hasCycle(ListNode* head)
{
	if (!head) {
		return false;
	}

	ListNode* step1 = head;
	ListNode* step2 = head;
	while (true) {
		step2 = step2->next;
		if (step2 == step1) {
			return true;
		}
		if (step2 == nullptr) {
			return false;
		}
		step2 = step2->next;
		if (step2 == step1) {
			return true;
		}
		if (step2 == nullptr) {
			return false;
		}
		step1 = step1->next;
	}
	return false;
}