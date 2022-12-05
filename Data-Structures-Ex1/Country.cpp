#include "Country.h"

Country::Country()
{
	this->_numOfCities = 0;
	this->_countryStructure = nullptr;
}

Country::Country(int numOfCities)
{
	this->_numOfCities = numOfCities;
	this->_countryStructure = new City[numOfCities];
}

void Country::setNumOfCities(int numOfCities)
{
	this->_numOfCities = numOfCities;
}

int Country::getNumOfCities() const
{
	return this->_numOfCities;
}

//City* Country::getCountryStructure(int cityNum) const
//{
//	return &(this->_countryStructure[cityNum]);
//}