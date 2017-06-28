#include <iostream>
#include <list>
#include "LinkedList.h"


using namespace std;

ListNode* partition(ListNode *head, int x);

int main()
{
	int nums[6] = { 1,4,3,2,5,2 };
	LinkedList *l = new LinkedList();
	l->creatList(nums, 6);
	l->displayList();
	auto h = l->getHead();
	auto ans = partition(h, 3);
	l->displayList();
	return 0;
}


ListNode * partition(ListNode * head, int x)
{
	if (head == nullptr)
		return head;
	ListNode *dummy_left = new ListNode(0);
	ListNode *dummy_right = new ListNode(0);
	ListNode *left = dummy_left;
	ListNode *right = dummy_right;
	while (head)
	{
		if (head->val < x) {
			left->next = head;
			left = head;
		}
		else {
			right->next = head;
			right = head;
		}
		head = head->next;
	}
	right->next = nullptr;
	left->next = dummy_right->next;

	head = dummy_left->next;

	return head;
}
