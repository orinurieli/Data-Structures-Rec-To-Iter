#pragma once
#include "City.h"
#include "ListNode.h"

class ItemType
{
private:
	City* _currCity;
	ListNode* _currNearbyCity;
	int _line;
	int _favoriteDistance;

public:
	ItemType();
	ItemType(City* currCity, ListNode* currNearbyCity, int line, int favoriteDistance);
	void setCity(City* currCity) { _currCity = currCity; }
	City* getCity() const { return _currCity; }
	void setCurrNearbyCity(ListNode* currNearbyCity) { _currNearbyCity = currNearbyCity; }
	ListNode* getCurrNearbyCity() const { return _currNearbyCity; }
	int getLine() const { return _line; }
	void setLine(int line) { _line = line; }
	int getFavoriteDistance() const { return _favoriteDistance; }
	void setFavoriteDistance(int favoriteDistance) { _favoriteDistance = favoriteDistance; }
};