#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n);

int main()
{
	int nums[1] = { 1 };
	LinkedList l;
	l.creatList(nums, 1);
	l.displayList();
	auto h = l.getHead();
	removeNthFromEnd(h, 1);
	l.displayList();
	return 0;
}

ListNode * removeNthFromEnd(ListNode * head, int n)
{
	if (!head)
		return nullptr;
	ListNode *cnt = head;
	int len = 0;
	while (cnt)
	{
		cnt = cnt->next;
		len++;
	}
	int tag = len - n - 1;
	if (tag < 0)
		return head->next;
	cnt = head;
	while (tag--)
	{
		cnt = cnt->next;
	}
	ListNode *tmp = cnt->next;
	cnt->next = tmp->next;
	delete[]tmp;
	return head;
}
