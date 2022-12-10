#pragma once

#include "ItemType.h"

class StackNode {
	ItemType _data;
	StackNode* _next;

private:
	StackNode();
	StackNode(ItemType data, StackNode* next);
	~StackNode();

	ItemType getData() const { return _data; }
	ItemType getNext() const { return _next; }

	ItemType setData(ItemType data) const { _data = data; }
	ItemType setNext(StackNode* next) const { _next = next; }

};