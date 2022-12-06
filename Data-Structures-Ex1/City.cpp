#pragma once

#include "City.h"

City::City()
{
	_cityNum = 0;
	_color = 1; 
	_nearbyCities = new List;
	_nextCity = nullptr;
}

City::City(int cityNum, City* nextCity)
{
	_cityNum = cityNum;
	_nextCity = nextCity;
	_color = 1; // todo change to array [0,1]
	_nearbyCities = new List;
}

void City::setColor(int color)
{
	_color = color;
}

int City::getColor() const
{
	return _color;
}

void City::setCityNumber(int cityNum)
{
	_cityNum = cityNum;
}

int City::getCityNumber() const
{
	return _cityNum;
}

City* City::getNextCity()
{
	return _nextCity;
}

List* City::getNearbyCities() const
{
	return _nearbyCities;
}

void City::insertNearbyCitiesToSortedList(City* nearbyCity)
{
	_nearbyCities->sortedInsert(nearbyCity);
}