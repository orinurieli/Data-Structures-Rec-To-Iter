#pragma once
#include "City.h"

//City::City()
//{
//	_cityNum = 0;
//	_nearbyCities = new List;
//	_color = 1; 
//}

City::City(int cityNum, City* nextCity)
{
	_cityNum = cityNum;
	_nearbyCities = new List;
	_color = 1;
}

void City::setColor(int color)
{
	_color = color;
}

void City::setCityNum(int cityNum)
{
	_cityNum = cityNum;
}

int City::getColor() const
{
	return _color;
}

int City::getCityNum() const
{
	return _cityNum;
}

List* City::getNearbyCities() const
{
	return _nearbyCities;
}

void City::insertNearbyCitiesToSortedList(ListNode* nearbyCity)
{
	cout << endl << "for city #" << _cityNum << endl;
	//cout << endl << "insert node" << nearbyCity->getCityNum() << " to city " << _cityNum << endl;
	cout << "before insert: " << endl;
	_nearbyCities->printList();
	cout << endl << endl;

	_nearbyCities->sortedInsert(_nearbyCities, nearbyCity);

	cout << "after insert: " << endl;
	_nearbyCities->printList();
	cout << endl << endl;

}