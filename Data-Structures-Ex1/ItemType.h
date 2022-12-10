#pragma once
#include "City.h"
#include "ListNode.h"

class ItemType
{
private:
	City* _cityNum;
	ListNode* _currNearbyCity;

public:
	ItemType();
	ItemType(City* cityNum, ListNode* currNearbyCity);
	void setCityNum(City* cityNum) { _cityNum = cityNum; }
	City* getCityNum() const { return _cityNum; }
	void setCurrNearbyCity(ListNode* currNearbyCity) { _currNearbyCity = currNearbyCity; }
	ListNode* getCurrNearbyCity() const { return _currNearbyCity; }
};