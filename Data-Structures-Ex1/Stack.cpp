#include "Stack.h"

Stack::Stack()
{
	_top = nullptr;
}

Stack::~Stack()
{
	makeEmpty();
}

void Stack::makeEmpty()
{
	StackNode* temp;

	while (_top != nullptr)
	{
		temp = _top;
		_top = _top->getNext();
		delete temp;
	}
}

int Stack::isEmpty()
{
	return _top == nullptr;
}

void Stack::Push(ItemType item)
{
	_top = new StackNode(item, _top);
}

ItemType Stack::Pop()
{
	if (isEmpty())
		cout << "The is a problem in the stack!" << endl;

	StackNode* temp = _top;
	ItemType item = _top->getData();
	_top = _top->getNext();
	delete temp;

	return item;
}

ItemType Stack::Top()
{
	return _top->getData();
}
