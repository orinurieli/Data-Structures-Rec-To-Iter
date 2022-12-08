#include "Country.h"

Country::Country()
{
	_numOfCities = 0;
	_numOfRoads = 0;
	_countryStructure = nullptr;
}

Country::Country(int numOfCities, int numOfRoads)
{
	_numOfCities = numOfCities;
	_numOfRoads = numOfRoads;
	_countryStructure = new City[numOfCities];
}

void Country::setNumOfCities(int numOfCities)
{
	_numOfCities = numOfCities;
}

void Country::setNumOfRoads(int numOfRoads)
{
	_numOfRoads = numOfRoads;
}

int Country::getNumOfCities() const
{
	return _numOfCities;
}

int Country::getNumOfRoads() const
{
	return _numOfRoads;
}

City* Country::getCityInCountryStructure(int cityNum) const
{
	return &_countryStructure[cityNum - 1];
}

void Country::initCountryStructure()
{
	_countryStructure = new City[_numOfCities];

	for (int i = 0; i < _numOfCities; i++)
	{
		_countryStructure[i].setCityNum(i + 1);
	}
}

void Country::fillCountryStructure(vector<pair<int, int>> roadLocation)
{
	int firstCityNumber, secondCityNumber;

	for (int i = 0; i < roadLocation.size(); i++)  // 4 3 
	{											   // 1-2 2-3 3-4 
		firstCityNumber = roadLocation[i].first; // 1
		secondCityNumber = roadLocation[i].second; // 2

		ListNode* nearbyCityToFirst = new ListNode(secondCityNumber); // 2
		ListNode* nearbyCityToSecond = new ListNode(firstCityNumber); // 1

		_countryStructure[firstCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToFirst);
		_countryStructure[secondCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToSecond);
	}
}
