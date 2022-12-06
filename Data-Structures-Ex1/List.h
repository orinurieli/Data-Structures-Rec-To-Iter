#pragma once
#include <iostream>
#include "ListNode.h"

using namespace std;

class List
{
private:
	ListNode* _head;
	ListNode* _tail;

public:
	List();
	~List();
	void makeEmpty();
	bool isEmpty();
	void sortedInsert(ListNode* newCity);
	void deleteNode(int node);
	ListNode* getHead() const;
	ListNode* getTail() const;
	void printList();
};