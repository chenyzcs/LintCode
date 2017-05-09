#include "my_list.h"

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->list_len = 0;
}

LinkedList::~LinkedList()
{
}

void LinkedList::CreateHead(int n)
{
	if (!this->head)
		this->head = new ListNode();
}

void LinkedList::CreateTail(int n)
{
}

bool LinkedList::IsEmpty() const
{
	if (!this->head)
		return false;
	if (this->head->next == nullptr)
	{
		std::cout << "The linkedlist is empty!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "The linkedlist is not empty!" << std::endl;
		return false;
	}
}

int LinkedList::FindItem(const int e) const
{
	return 0;
}

int LinkedList::GetItem(int idx) const
{
	return 0;
}

void LinkedList::Insert(int idx, const int e)
{
	if (idx < 0)
		return;
	
	int size = 0;
	if (idx > list_len)
	{
		ListNode *pre = head;
		ListNode *rea = head->next;
		while (rea)
		{
			pre = rea;
			rea = rea->next;
		}
		list_len++;
		ListNode *tmp = new ListNode(e);
		pre->next = tmp;
		tmp->next = rea;
	}
	else
	{
		ListNode *pre = head;
		ListNode *rea = head->next;
		while (size < idx)
		{
			pre = rea;
			rea = rea->next;
			size++;
		}
		list_len++;
		ListNode *tmp = new ListNode(e);
		pre->next = tmp;
		tmp->next = rea;
	}
}

void LinkedList::DeleteElement(const int e)
{
	ListNode *pre = head;
	ListNode *rea = head->next;
	bool isElementFlag = false;
	while (rea)
	{
		if (rea->val == e)
		{
			isElementFlag = true;
			break;
		}
		pre = rea;
		rea = rea->next;
	}
	if (isElementFlag)
	{
		pre->next = rea->next;
		delete[]rea;
		this->list_len = this->list_len--;
	}
}

void LinkedList::DeleteLocation(const int idx)
{
}

void LinkedList::PrintList() const
{
	ListNode *pre = head;
	while (pre->next)
	{
		std::cout << pre->val << "-->";
		pre = pre->next;
	}
	std::cout << pre->val << std::endl;
}

void LinkedList::Clear()
{
}

ListNode * LinkedList::GetHead() const
{
	return this->head;
}
