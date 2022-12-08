#include "Stack.h"

Stack::Stack()
{
	_top = NULL;
}

Stack::~Stack()
{
	makeEmpty();
}

void Stack::makeEmpty()
{
	StackNode* temp;

	while (_top != NULL)
	{
		temp = _top;
		_top = _top->getNext();
		delete temp;
	}
}

int Stack::isEmpty()
{
	return (_top == NULL);
}

void Stack::Push(ItemType item)
{
	_top == new StackNode(item, _top);
}

ItemType Stack::Pop()
{
	if (isEmpty())
		return NULL;

	StackNode* temp = _top;
	ItemType item = _top->getData();
	_top = _top->getNext();

	delete temp;

	return item;
}
