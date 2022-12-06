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
	return _countryStructure[cityNum].getNearbyCities();
}

void Country::initCountryStructure()
{
	_countryStructure.resize(_numOfCities);

	for (int i = 0; i < _numOfCities; i++)
	{
		_countryStructure[i].setCityNum(i + 1);
	}
}

void Country::fillCountryStructure(vector<pair<int, int>> roadLocation)
{
	int firstCityNumber, secondCityNumber;

	for (int i = 0; i < roadLocation.size(); i++)  // 5 5 
	{											   // 1-4 1-2 3-5 2-5 2-3
		firstCityNumber = roadLocation[i].first;
		secondCityNumber = roadLocation[i].second;

		//TODO: check input
		ListNode* nearbyCityToFirst = new ListNode(secondCityNumber);
		ListNode* nearbyCityToSecond = new ListNode(firstCityNumber);
		_countryStructure[firstCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToFirst);
		_countryStructure[secondCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToSecond);
	}
}
