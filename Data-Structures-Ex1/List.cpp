#include "List.h"

List::List(ListNode* head)
{
	_head = head;
}

List::~List()
{
	ListNode* curr = _head;

	while (curr != nullptr) 
	{
		ListNode* next = curr->getNextCity();
		delete curr;
		curr = next;
	}
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
	if (!toDeleteAfter || !toDeleteAfter->getNextCity()) 
		return;

	ListNode* toDelete = toDeleteAfter->getNextCity();
	toDeleteAfter->setNextCity(toDelete->getNextCity());
	delete toDelete;
}

void List::insertAfter(ListNode* prevNode, int cityNum)
{
	if (!prevNode) 
		return;

	ListNode* newNode = new ListNode(cityNum);
	newNode->setNextCity(prevNode->getNextCity());
	prevNode->setNextCity(newNode);
}

void List::sortedInsert(List* lst, ListNode* newNode) 
{
	if (newNode == nullptr) 
		return;  // don't insert a null node

	ListNode* curr = lst->getHead();

	if (curr == nullptr) 
	{
		// inserting into an empty list
		lst->setHead(newNode);
		newNode->setNextCity(nullptr);
	}
	else if (newNode->getCityNum() < curr->getCityNum()) 
	{
		// inserting new node at the beginning of the list
		newNode->setNextCity(curr);
		lst->setHead(newNode);
	}
	else 
	{
		// search for the correct position to insert the new node
		while (curr->getNextCity() != nullptr && curr->getNextCity()->getCityNum() < newNode->getCityNum())
			curr = curr->getNextCity();
		
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
