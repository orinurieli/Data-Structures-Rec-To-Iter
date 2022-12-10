#pragma once
#include "City.h"
#include "ListNode.h"

class ItemType
{
private:
	City* _cityNum;
	ListNode* _currNearbyCity;
	int _line;

public:
	ItemType();
	ItemType(City* cityNum, ListNode* currNearbyCity, int line);
	void setCityNum(City* cityNum) { _cityNum = cityNum; }
	City* getCityNum() const { return _cityNum; }
	void setCurrNearbyCity(ListNode* currNearbyCity) { _currNearbyCity = currNearbyCity; }
	ListNode* getCurrNearbyCity() const { return _currNearbyCity; }
	int getLine() const { return _line; }
	void setLine(int line) { _line = line; }
};