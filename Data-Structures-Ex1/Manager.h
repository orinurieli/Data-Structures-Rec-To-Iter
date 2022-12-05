#pragma once
#include <vector>
#include <iostream>

#include "Country.h"
#include "City.h"
#include "List.h"

using namespace std;

enum class eColors
{
	WHITE = 0,
	BLACK = 1
};

class Manager
{
private:
	int _numOfCities;
	int _numOfRoads;
	vector<pair<int, int>> _roadPair;
	City* _startingPoint;
	City* _endPoint;
	Country _country;
	eColors* _cityColor; // colors = [{color: white, num: 0}, {color: black, num: 1} ] 

public:
	void run();
	void getinputNumberOfCitiesandRoads();
	void getinputStartingAndEndPoint();
	void getPairsOfRoadLocation();

	int getNumberOfCities() { return _numOfCities; };
	int getNumberOfRoads() { return _numOfRoads; };
	City* getStartingPoint() { return _startingPoint; };
	City* getEndPoint() { return _endPoint; };

	bool isValid(int input) { return (input >= 0 && input <= _numOfCities) ? true : false; };

	eColors* buildCitiesColors();
	Country* buildCountry(eColors* cities);

	int townDistanceRec(Country* country, City* startCity, City* endCity, eColors* colors);
	//void townDistanceIter(Country* country, City* startCity, City* endCity, eColors* colors);


};