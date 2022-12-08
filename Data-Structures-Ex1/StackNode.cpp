
#include "StackNode.h"

StackNode::StackNode()
{
	_data = new ItemType(); // add members inside
	_next = nullptr;
}

StackNode::StackNode(ItemType data, StackNode* next)
{
	_data = data;
	_next = next;
}

StackNode::~StackNode()
{
	// todo delete memory
}
