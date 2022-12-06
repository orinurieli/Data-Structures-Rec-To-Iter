#include "List.h"


List::List()
{
	_head = new ListNode();
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
	ListNode *curr;

	if ((_head == nullptr) || (_head->getCityNum() >= newNode->getCityNum()))
	{
		//newNode->getNextCity() = _head; 
		_head = newNode;
	}

	curr = _head;
	while ((curr->getNextCity() != nullptr) &&
		  (curr->getNextCity()->getCityNum() < newNode->getCityNum()))
	{
		curr = curr->getNextCity();
	}
	//*newNode->getNextCity() = curr->getNextCity();
	//curr->getNextCity() = newNode;
}

//
//void List::printList()
//{
//	City* curr = _head;
//
//	if (isEmpty()) {
//		cout << "List empty" << endl;
//		return;
//	}
//
//	while (curr != nullptr) {
//		cout << curr->_cityNum << " ";
//		curr = curr->_next;
//	}
//}

ListNode* List::getHead() const
{
	return this->_head;
}

ListNode* List::getTail() const
{
	return this->_tail;
}