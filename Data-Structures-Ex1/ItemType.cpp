#include "ItemType.h"

ItemType::ItemType()
{
	_cityNum = 0;
	_currNearbyCity = nullptr;
}

ItemType::ItemType(int cityNum, ListNode* currNearbyCity)
{
	_cityNum = cityNum;
	_currNearbyCity = currNearbyCity;
}