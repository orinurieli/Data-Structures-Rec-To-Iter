#include "Country.h"

Country::Country()
{
	_numOfCities = 0;
	_numOfRoads = 0;
	_countryStructure.resize(0);
}

Country::Country(int numOfCities, int numOfRoads)
{
	_numOfCities = numOfCities;
	_numOfRoads = numOfRoads;
	_countryStructure.resize(numOfCities);
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

List* Country::getCountryStructure(int cityNum) const
{
	return _countryStructure[cityNum - 1];
}

void Country::initCountryStructure()
{
	_countryStructure.resize(_numOfCities);

	for (int i = 0; i < _numOfCities; i++)
	{
		_countryStructure[i].setHead(new ListNode(i + 1));
	}
}

void Country::fillCountryStructure(vector<pair<int, int>> roadLocation)
{
	int firstCityNumber, secondCityNumber;

	for (int i = 0; i < roadLocation.size(); i++)  // 4 3 
	{											   // 1-2 2-3 3-4 
		firstCityNumber = roadLocation[i].first; // 1
		secondCityNumber = roadLocation[i].second; // 2

		//TODO: check input
		ListNode* nearbyCityToFirst = new ListNode(secondCityNumber); // 2
		ListNode* nearbyCityToSecond = new ListNode(firstCityNumber); // 1
		_countryStructure[firstCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToFirst);
		_countryStructure[secondCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToSecond);
	}
}
