#ifndef MY_LIST_H
#define MY_LIST_H

#include <iostream>

#define INF 0xffff

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val = INF) :val(val), next(nullptr) {}
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void CreateHead(int n);
	void CreateTail(int n);
	bool IsEmpty() const;
	int FindItem(const int e) const;
	int GetItem(int idx) const;
	void Insert(int idx, const int e);
	void DeleteElement(const int e);
	void DeleteLocation(const int idx);
	void PrintList() const;
	void Clear();
	ListNode *GetHead() const;
private:
	ListNode *head;
	int list_len;
};

#endif // !MY_LIST_HMY_LIST_H
