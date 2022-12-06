#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Country.h"
#include "City.h"
#include "List.h"

using namespace std;


class Manager
{
private:
	Country _country;
	City* _srcCityNumber;
	City* _destCityNumber;
	vector<pair<int, int>> _roadLocation;
	int* _citiesColorsArr;

public:
	Manager();
	void run();

	int* buildCitiesColorsArr();

	int townDistanceRec(Country* country, City* srcCityNumber, City* destCityNumber, int* citiesColorsArr);
	int townDistanceIter(Country* country, City* srcCityNumber, City* destCityNumber, int* citiesColorsArr);

	void getinputNumberOfCitiesandRoads();
	void getinputStartingAndEndPoint();
	void getPairsOfRoadLocation();
	void buildCountryStructure();

	//int getNumberOfCities() { return _numOfCities; };
	//int getNumberOfRoads() { return _numOfRoads; };
	City* getSrcCityNumber() { return _srcCityNumber; }
	City* getDestCityNumber() { return _destCityNumber; }

	bool isValidInput(int inputUser, int from, int to); /*{ return (inputUser >= 0 && inputUser <= _country.getNumOfCities()) ? true : false; }*/
};