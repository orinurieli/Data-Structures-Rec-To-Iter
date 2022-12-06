#pragma once
#include <iostream>
#include "City.h"

class City;

using namespace std;

class List
{
private:
	City* _head;
	City* _tail;

public:
	List();
	~List();
	void makeEmpty();
	bool isEmpty();
	void sortedInsert(City* newCity);
	void deleteNode(int node);
	City* getHead() const;
	City* getTail() const;
	void printList();
};