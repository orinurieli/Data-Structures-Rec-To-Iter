#include "ItemType.h"

ItemType::ItemType()
{
	_currCity = nullptr;
	_currNearbyCity = nullptr;
	_line = 0;
	_favoriteDistance = 0;
}

ItemType::ItemType(City* currCity, ListNode* currNearbyCity, int line, int favoriteDistance)
{
	_currCity = currCity;
	_currNearbyCity = currNearbyCity;
	_line = line;
	_favoriteDistance = favoriteDistance;
}