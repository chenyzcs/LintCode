#include <iostream>
#include <stack>
#include "LinkedList.h"

using namespace std;

ListNode *addLists2(ListNode *l1, ListNode *l2);

int main()
{
	int nums1[3] = { 6,1,7 };
	int nums2[3] = { 2,9,5 };
	LinkedList l1, l2;
	l1.creatList(nums1, 3);
	l2.creatList(nums2, 3);
	l1.displayList();
	l2.displayList();
	auto h1 = l1.getHead();
	auto h2 = l2.getHead();
	printList(h1);
	printList(h2);
	addLists2(h1, h2);
	return 0;
}

ListNode * addLists2(ListNode * l1, ListNode * l2)
{
	// reverse two lists
	ListNode *head1 = new ListNode(0);
	ListNode *head2 = new ListNode(0);
	ListNode *h1 = head1;
	ListNode *h2 = head2;
	stack<int> stk1,stk2;
	while (l1)
	{
		stk1.push(l1->val);
		l1 = l1->next;
	}
	while (l2)
	{
		stk2.push(l2->val);
		l2 = l2->next;
	}
	while (!stk1.empty())
	{
		int val = stk1.top();
		ListNode *tmp = new ListNode(val);
		h1->next = tmp;
		h1 = h1->next;
		stk1.pop();
	}
	while (!stk2.empty())
	{
		int val = stk2.top();
		ListNode *tmp = new ListNode(val);
		h2->next = tmp;
		h2 = h2->next;
		stk2.pop();
	}
	// add two lists
	printList(head1);
	printList(head2);
	h1 = head1->next;
	h2 = head2->next;
	ListNode *ret = new ListNode(0);
	ListNode *ans = ret;
	int carry = 0;
	while (h1 && h2)
	{
		int val = h1->val + h2->val + carry;
		carry = (val > 9) ? 1 : 0;
		val = (val > 9) ? val % 10 : val;
		ListNode *tmp = new ListNode(val);
		ret->next = tmp;
		ret = ret->next;
		h1 = h1->next;
		h2 = h2->next;
	}
	while (h1) {
		ListNode *tmp = new ListNode(h1->val + carry);
		carry = 0;
		ret->next = tmp;
		ret = tmp;
		h1 = h1->next;
	}
	while (h2) {
		ListNode *tmp = new ListNode(h2->val + carry);
		carry = 0;
		ret->next = tmp;
		ret = tmp;
		h2 = h2->next;
	}
	if (!h1 && !h2 && carry) {
		ListNode *tmp = new ListNode(carry);
		ret->next = tmp;
		ret = tmp;
	}
	printList(ans);
	// reverse ret
	ans = ans->next;
	ListNode *head = new ListNode(0);
	ListNode *retHead = head;
	stack<int> stk;
	while (ans)
	{
		stk.push(ans->val);
		ans = ans->next;
	}
	while (!stk.empty())
	{
		int val = stk.top();
		ListNode *tmp = new ListNode(val);
		head->next = tmp;
		head = head->next;
		stk.pop();
	}
	printList(retHead->next);
	return retHead->next;
}
