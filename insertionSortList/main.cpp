#include <iostream>
#include <vector>
#include <algorithm>
#include "my_list.h"

using namespace std;

ListNode *insertionSortList(ListNode *head);

int main()
{
	LinkedList a;
	a.CreateHead(1);
	a.IsEmpty();
	for (int i = 1; i < 5; i++)
		a.Insert(i, i);
	//a.Insert(0, 2);
	//a.Insert(1, 1);
	
	a.PrintList();
	auto x = insertionSortList(a.GetHead()->next);
	while (x)
	{
		cout << x->val << "-->";
		x = x->next;
	}
	return 0;
}

ListNode *insertionSortList(ListNode *head)
{
	ListNode *h = new ListNode(0xffff);
	h->next = head;
	ListNode *pos_pre;
	ListNode *pos_rea;
	ListNode *curr = h->next;
	ListNode *pos;
	while (curr->next)
	{
		pos = h;
		pos_pre = nullptr;
		pos_rea = nullptr;
		while (pos->next != curr->next)
		{
			if (pos->next->val > curr->next->val)
			{
				pos_pre = pos;
				pos_rea = pos->next;
				break;
			}
			pos = pos->next;
			/*if (!pos)
				break;*/
		}
		if (!pos_pre)
		{
			curr = curr->next;
			continue;
		}
		ListNode *tmp = curr->next->next;
		curr->next->next = pos->next;
		pos->next = curr->next;
		curr->next = tmp;
		ListNode *l = h;
		while (l)
		{
			cout << l->val << "-->";
			l = l->next;
		}
		cout << endl;
	}
	return h;
}