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
	ListNode *tmp = head;
	
	for (int i = 0; i < len; i++) {
		tmp = new ListNode(inputArr[i]);
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
