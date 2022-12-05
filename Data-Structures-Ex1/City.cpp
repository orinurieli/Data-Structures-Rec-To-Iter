#pragma once
#include "City.h"
#include "List.h"


City::City(int cityNum, City* nextCity)
{
	_cityNum = cityNum;
	_color = 1; // todo change to array [0,1]
	_nearbyCities = new List;
	_nextCity = nextCity;
}

void City::setCityNumber(int cityNum)
{
	this->_cityNum = cityNum;
}

int City::getCityNumber() const
{
	return this->_cityNum;
}

List* City::getNearbyCities() const
{
	return this->_nearbyCities;
}

//void City::insertNearbyCitiesToSortedList(City* nearbyCity)
//{
//	_nearbyCities->sortedInsert(nearbyCity);
//}