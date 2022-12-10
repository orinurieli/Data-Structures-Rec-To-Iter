#pragma once
#include <iostream>
#include "ListNode.h"

using namespace std;

class List
{
private:
	ListNode* _head;

public:
	List(ListNode* head = nullptr);
	~List();
	void makeEmpty();
	bool isEmpty();
	void sortedInsert(List* lst, ListNode* newCity);
	void deleteAfter(ListNode* toDeleteAfter);
	void setHead(ListNode* head) { _head = head; }
	ListNode* getHead() const { return this->_head; }
	void printList();
};