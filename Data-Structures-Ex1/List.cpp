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
	return _head == nullptr;
}

void List::sortedInsert(List* lst, ListNode* newNode)
{
	ListNode* curr = lst->getHead();

	if (newNode == nullptr) return;
	if (curr == nullptr)
	{
		curr = newNode;
		lst->setHead(curr);
		curr->setNextCity(nullptr);
		return;
	}

	if (curr->getNextCity() == nullptr && curr->getCityNum() > newNode->getCityNum()) {
		newNode->setNextCity(curr);
		curr->setNextCity(nullptr);
		lst->setHead(newNode);
		return;
	}

	while (curr->getNextCity() != nullptr && curr->getNextCity()->getCityNum() < newNode->getCityNum())
		curr = curr->getNextCity();

	newNode->setNextCity(curr->getNextCity());
	curr->setNextCity(newNode);
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