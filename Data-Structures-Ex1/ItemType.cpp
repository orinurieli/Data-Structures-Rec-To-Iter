#include "ItemType.h"

ItemType::ItemType()
{
	_currCity = nullptr;
	_currNearbyCity = nullptr;
	_line = 0;
	_preferreDistance = 0;
}

ItemType::ItemType(City* currCity, ListNode* currNearbyCity, int line, int preferreDistance)
{
	_currCity = currCity;
	_currNearbyCity = currNearbyCity;
	_line = line;
	_preferreDistance = preferreDistance;
}