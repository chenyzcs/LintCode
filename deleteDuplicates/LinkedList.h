#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

class LinkedList {
public:
	LinkedList() {}
	ListNode *creatList(int *inputArr, int len);
	bool isEmpty();
	void displayList();
	ListNode *getHead();
private:
	ListNode *head = nullptr;
};

ListNode* LinkedList::creatList(int *inputArr, int len)
{
	if (len <= 0)
		return nullptr;
	if (isEmpty())
		head = new ListNode(inputArr[0]);
	ListNode *tmp = head;

	for (int i = 1; i < len; i++) {
		ListNode *tmp_val = new ListNode(inputArr[i]);
		tmp->next = tmp_val;
		tmp = tmp->next;
	}
	return head;
}

bool LinkedList::isEmpty()
{
	return head == nullptr;
}

void LinkedList::displayList()
{
	ListNode *tmp = head;
	while (tmp)
	{
		std::cout << tmp->val << "-->";
		tmp = tmp->next;
	}
	std::cout << "null" << std::endl;
}

ListNode * LinkedList::getHead()
{
	return this->head;
}

#endif // !LINKEDLIST_H__
