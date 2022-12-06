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

City* Country::getCountryStructure(int cityNum) const
{
	return &(this->_countryStructure[cityNum]);
}

void Country::initCountryStructure()
{
	_countryStructure = new City[_numOfCities];

	for (int i = 0; i < _numOfCities; i++)
	{
		_countryStructure[i].setCityNumber(i + 1);
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
		City* nearbyCityToFirst = new City(secondCityNumber);
		City* nearbyCityToSecond = new City(firstCityNumber);
		_countryStructure[firstCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToFirst);
		_countryStructure[secondCityNumber - 1].insertNearbyCitiesToSortedList(nearbyCityToSecond);
	}
}
