#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode *deleteDuplicates(ListNode *head);

int main()
{
	int nums[5] = { 1,1,2,3,3 };
	LinkedList *l = new LinkedList();
	l->creatList(nums, 5);
	l->displayList();
	auto h = l->getHead();
	deleteDuplicates(h);
	l->displayList();
	return 0;
}

ListNode * deleteDuplicates(ListNode * head)
{
	if (!head)
		return nullptr;
	ListNode* pre = new ListNode(0xffff);
	pre->next = head;
	ListNode* rea = head;
	while (rea) {
		if (pre->val == rea->val) {
			pre->next = rea->next;
			ListNode *tmpNode = rea;
			rea = rea->next;
			delete[]tmpNode;
		}
		else {
			pre = rea;
			rea = rea->next;
		}
	}
	return head;
}
