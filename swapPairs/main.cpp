#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode* swapPairs(ListNode* head);

int main()
{
	int nums[4] = { 1,2,3,4 };
	LinkedList l;
	l.creatList(nums, 4);
	l.displayList();
	auto h = l.getHead();
	swapPairs(h);
	l.displayList();
	return 0;
}

ListNode * swapPairs(ListNode * head)
{
	if (!head)
		return nullptr;
	ListNode *pre = head;
	ListNode *rea = head->next;

	while (rea)
	{
		int tmp_val = pre->val;
		pre->val = rea->val;
		rea->val = tmp_val;
		pre = rea->next;
		if (!pre)
			break;
		rea = pre->next;
	}
	return head;
}
