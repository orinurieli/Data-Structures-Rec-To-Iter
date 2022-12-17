#pragma once
#include "City.h"
#include "ListNode.h"

class ItemType
{
private:
	City* _currCity;
	ListNode* _currNearbyCity;
	int _line;
	int _preferreDistance;

public:
	ItemType();
	ItemType(City* currCity, ListNode* currNearbyCity, int line, int preferreDistance);
	void setCity(City* currCity) { _currCity = currCity; }
	City* getCity() const { return _currCity; }
	void setCurrNearbyCity(ListNode* currNearbyCity) { _currNearbyCity = currNearbyCity; }
	ListNode* getCurrNearbyCity() const { return _currNearbyCity; }
	int getLine() const { return _line; }
	void setLine(int line) { _line = line; }
	int getPreferreDistance() const { return _preferreDistance; }
	void setPreferreDistance(int preferreDistance) { _preferreDistance = preferreDistance; }
};