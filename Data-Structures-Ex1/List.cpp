#include "List.h"


List::List()
{
	_head = nullptr;
	_tail = _head;
}

List::~List()
{
	makeEmpty();
}

void List::makeEmpty()
{
	_head = _tail = nullptr;
}

bool List::isEmpty()
{
	return _head == nullptr ? true : false;
}

void List::sortedInsert(ListNode* newNode)
{
	if (newNode == nullptr) return;

	ListNode* curr;

	if ((_head == nullptr) || (_head->getCityNum() >= newNode->getCityNum()))
	{
		ListNode* nextCity = newNode->getNextCity();
		nextCity = _head;
		_head = newNode;
	}

	
}


void List::printList()
{
	ListNode* curr = _head;

	if (isEmpty()) {
		cout << "List empty" << endl;
		return;
	}

	while (curr != nullptr) {
		cout << curr->getCityNum() << " ";
		curr = curr->getNextCity();
	}
}

ListNode* List::getHead() const
{
	return this->_head;
}

ListNode* List::getTail() const
{
	return this->_tail;
}