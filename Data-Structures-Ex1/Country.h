#pragma once
#include <iostream>
#include <vector>
#include "City.h"
#include "List.h"

using namespace std;

class Country
{
private:
	int _numOfCities;
	int _numOfRoads;
	City* _countryStructure;

public:
	Country();
	Country(int numOfCities, int numOfRoads);
	void setNumOfCities(int numOfCities);
	void setNumOfRoads(int numOfRoads);
	int getNumOfCities() const;
	int getNumOfRoads() const;
	void initCountryStructure();
	void fillCountryStructure(vector<pair<int, int>> roadLocation);
	City* getCountryStructure(int cityNum) const;
};
