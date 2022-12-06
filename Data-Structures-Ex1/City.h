#pragma once
#include "List.h"

class List;

class City
{
private:
	int _cityNum;
	int _color;
	List* _nearbyCities;
	City* _nextCity;

public:
	City(int cityNum = 0, City* nextCity = nullptr);
	void setCityNumber(int cityNum);
	void setColor(int color);
	int getColor() const; 
	int getCityNumber() const;
	City* getNextCity();
	List* getNearbyCities() const;
	void insertNearbyCitiesToSortedList(City* nearbyCity);
};