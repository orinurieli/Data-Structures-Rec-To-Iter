#include "Stack.h"

Stack::Stack()
{
	_top = 0;
}

void Stack::makeEmpty()
{
	_top = 0;
}

int Stack::isEmpty()
{
	return (_top == 0);
}

int Stack::isFull()
{
	return (_top == MAX_SIZE);
}

