#include <iostream>
#include <stack>
#include "LinkedList.h"

using namespace std;

ListNode *reverse(ListNode *head);

int main()
{
	int nums[3] = { 1,2,3 };
	LinkedList *l = new LinkedList();
	l->creatList(nums, 3);
	l->displayList();
	auto h = l->getHead();
	reverse(h);
	l->displayList();
	return 0;
}

ListNode * reverse(ListNode * head)
{
	if (!head)
		return nullptr;
	stack<int> stk;
	ListNode *tmp = head;
	while (tmp)
	{
		stk.push(tmp->val);
		tmp = tmp->next;
	}
	tmp = new ListNode(0);
	ListNode *ret = tmp;
	while (!stk.empty())
	{
		int val_t = stk.top();
		ListNode *val = new ListNode(val_t);
		tmp->next = val;
		tmp = val;
		stk.pop();
	}
	head = ret->next;
	return head;
}