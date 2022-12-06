#pragma once
#include "List.h"

class City
{
private:
	int _cityNum;
	int _color;
	List* _nearbyCities;

public:
	//City();
	City(int cityNum = 0, City* nextCity = nullptr);
	void setCityNum(int cityNum);
	void setColor(int color);
	int getColor() const; 
	int getCityNum() const;
	List* getNearbyCities() const;
	void insertNearbyCitiesToSortedList(ListNode* nearbyCity);
};