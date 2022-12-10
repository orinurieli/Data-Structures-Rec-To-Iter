#pragma once
#include "ItemType.h"

class StackNode 
{
private:
	ItemType _data;
	StackNode* _next;

public:
	StackNode();
	StackNode(ItemType data, StackNode* next = nullptr);
	ItemType getData() const { return _data; }
	StackNode* getNext() const { return _next; }
	void  setData(ItemType data) { _data = data; }
	void setNext(StackNode* next) { _next = next; }
};