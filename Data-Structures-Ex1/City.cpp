#include "City.h"

City::City(int cityNum, City* nextCity)
{
	_cityNum = cityNum;
	_nearbyCities = new List;
}

void City::setCityNum(int cityNum)
{
	_cityNum = cityNum;
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
	_nearbyCities->sortedInsert(_nearbyCities, nearbyCity);
}