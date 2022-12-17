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

void List::sortedInsert(List* lst, ListNode* newNode) {
	if (newNode == nullptr) {
		return;  // Don't insert a null node
	}

	ListNode* curr = lst->getHead();
	if (curr == nullptr) {
		// Inserting into an empty list
		lst->setHead(newNode);
		newNode->setNextCity(nullptr);
	}
	else if (newNode->getCityNum() < curr->getCityNum()) {
		// Inserting new node at the beginning of the list
		newNode->setNextCity(curr);
		lst->setHead(newNode);
	}
	else {
		// Search for the correct position to insert the new node
		while (curr->getNextCity() != nullptr && curr->getNextCity()->getCityNum() < newNode->getCityNum()) {
			curr = curr->getNextCity();
		}
		newNode->setNextCity(curr->getNextCity());
		curr->setNextCity(newNode);
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
