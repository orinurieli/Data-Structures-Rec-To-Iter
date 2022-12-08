#pragma once
#include "List.h"

class City
{
private:
	int _cityNum;
	List* _nearbyCities;

public:
	City(int cityNum = 0, City* nextCity = nullptr);
	void setCityNum(int cityNum);
	int getCityNum() const;
	List* getNearbyCities() const;
	void insertNearbyCitiesToSortedList(ListNode* nearbyCity);
};