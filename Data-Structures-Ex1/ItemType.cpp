#include "ItemType.h"

ItemType::ItemType()
{
	_cityNum = nullptr;
	_currNearbyCity = nullptr;
	_line = 0;
}

ItemType::ItemType(City* cityNum, ListNode* currNearbyCity, int line)
{
	_cityNum = cityNum;
	_currNearbyCity = currNearbyCity;
	_line = line;
}