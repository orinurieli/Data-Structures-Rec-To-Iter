#include "ItemType.h"

ItemType::ItemType()
{
	_cityNum = nullptr;
	_currNearbyCity = nullptr;
}

ItemType::ItemType(City* cityNum, ListNode* currNearbyCity)
{
	_cityNum = cityNum;
	_currNearbyCity = currNearbyCity;
}