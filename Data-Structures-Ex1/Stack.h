#pragma once
#include <iostream>
#include "StackNode.h"
#include "ItemType.h"

using namespace std;

class Stack 
{
private:
	StackNode* _top;

public:
	Stack();
	~Stack();
	void makeEmpty();
	int isEmpty();
	void Push(ItemType item);
	ItemType Pop(); 
	ItemType Top();
};