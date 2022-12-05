#include <iostream>
#include "List.h"


List::List()
{
	City* city = new City(0, NULL);
	_head = city;
	_tail = _head; // todo dummy head
}

List::~List()
{
	makeEmpty();
}

void List::makeEmpty()
{

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

//void List::sortedInsert(City* newNode)
//{
//	// Create the new Node.
//	City* newNode = new City(data, nullptr);
//
//	if ((_head == nullptr) || (_head->getCityNumber() >= newNode->getCityNumber()))
//	{
//		newNode->getNext() = _head;
//		_head = newNode;
//	}
//
//	// Traverse till end of list
//	City* temp = _head;
//	while (temp->getNext() != NULL) {
//		// Update temp
//		temp = temp->getNext();
//	}
//
//	// Insert at the last
//	temp->getNext() = newNode;
//}
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