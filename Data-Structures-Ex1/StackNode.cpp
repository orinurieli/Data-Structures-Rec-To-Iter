#include "StackNode.h"

StackNode::StackNode()
{
	_next = nullptr;
}

StackNode::StackNode(ItemType data, StackNode* next)
{
	_data = data;
	_next = next;
}
