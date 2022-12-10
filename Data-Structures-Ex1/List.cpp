#include "List.h"

List::List(ListNode* head)
{
	_head = head;
}

List::~List()
{
	ListNode* curr = _head;
	ListNode* currNext = curr->getNextCity();

	while (currNext != nullptr)
	{
		delete curr;
		curr = currNext;
		currNext = currNext->getNextCity();
	}
	delete curr;
}

void List::makeEmpty()
{
	_head = nullptr;
}

bool List::isEmpty()
{
	return _head == nullptr;
}

void List::deleteAfter(ListNode* toDeleteAfter)
{
	ListNode* toDelete = toDeleteAfter->getNextCity();
	ListNode* temp = toDeleteAfter->getNextCity()->getNextCity();
	
	if (toDeleteAfter->getNextCity() == nullptr)
		return;
		
	toDeleteAfter->setNextCity(temp);
	delete(toDelete);
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
