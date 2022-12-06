#include "List.h"

List::List()
{
	_head = new City();
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

// Function to delete the node at given position
//void List::deleteNode(int nodeOffset)
//{
//	City* temp1 = _head;
//	City* temp2;
//	int ListLen = 0;
//
//	if (_head == NULL) {
//		cout << "List empty." << endl;
//		return;
//	}
//
//	// Find length of the linked-list.
//	while (temp1 != NULL) {
//		temp1 = temp1->getNext();
//		ListLen++;
//	}
//
//	if (ListLen < nodeOffset) {
//		cout << "Index out of range"
//			<< endl;
//		return;
//	}
//
//	temp1 = _head;
//
//	// Deleting the head.
//	if (nodeOffset == 1) {
//
//		// Update head
//		_head = _head->getNext();
//		delete temp1;
//		return;
//	}
//
//	// Traverse list 
//	while (nodeOffset-- > 1) {
//
//		// Update temp2
//		temp2 = temp1;
//
//		// Update temp1
//		temp1 = temp1->getNext();
//	}
//
//	// Change the next pointer of the previous node
//	temp2->getNext() = temp1->getNext();
//
//	// Delete the node
//	delete temp1;
//}

void List::sortedInsert(City* newNode)
{
	City* curr;

	if ((_head == nullptr) || (_head->getCityNumber() >= newNode->getCityNumber()))
	{
		//newNode->getNextCity() = _head; 
		_head = newNode;
	}

	curr = _head;
	while ((curr->getNextCity() != nullptr) &&
		  (curr->getNextCity()->getCityNumber() < newNode->getCityNumber()))
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

City* List::getHead() const
{
	return this->_head;
}

City* List::getTail() const
{
	return this->_tail;
}