#pragma once
#include <iostream>

#include "City.h"

using namespace std;

class Country
{
private:
	int _numOfCities;
	City* _countryStructure; // City1 --> City2 -->

public:
	Country();
	Country(int numOfCities);
	void setNumOfCities(int numOfCities);
	int getNumOfCities() const;
	//City* getCountryStructure(int cityNum) const;
};
