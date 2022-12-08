#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "ItemType.h"
#include "StackNode.h"

class Stack {
private:
	StackNode* _top; // pointer to top item

public:
	Stack();
	~Stack();

	void makeEmpty();
	int isEmpty();

	void Push(ItemType item);
	ItemType Pop(); // return itemType* ?
	ItemType Top();
};