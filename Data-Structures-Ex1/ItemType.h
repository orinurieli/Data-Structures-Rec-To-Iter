#pragma once
#include "ListNode.h"

class ItemType
{
private:
	int _cityNum;
	ListNode* _currNearbyCity;

public:
	ItemType();
	ItemType(int cityNum, ListNode* currNearbyCity);
	void setCityNum(int cityNum) { _cityNum = cityNum; }
	int getCityNum() const { return _cityNum; }
	void setCurrNearbyCity(ListNode* currNearbyCity) { _currNearbyCity = currNearbyCity; }
	ListNode* getCurrNearbyCity() const { return _currNearbyCity; }
};