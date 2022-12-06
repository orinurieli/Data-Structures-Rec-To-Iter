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

//enum class eColors
//{
//	WHITE = 0,
//	BLACK = 1
//};

class Manager
{
private:
	Country _country;
	City* _srcCityNumber;
	City* _destCityNumber;
	vector<pair<int, int>> _roadLocation;
	//eColors* _cityColor; // colors = [{color: white, num: 0}, {color: black, num: 1} ] 
	//int _numOfCities;
	//int _numOfRoads;

public:
	void run();

	//eColors* buildCitiesColors();

	int townDistanceRec(Country* country, City* startCity, City* endCity/*, eColors* colors*/);
	int townDistanceIter(Country* country, City* startCity, City* endCity/*, eColors* colors*/);

	void getinputNumberOfCitiesandRoads();
	void getinputStartingAndEndPoint();

	int getNumberOfCities() { return _numOfCities; };
	int getNumberOfRoads() { return _numOfRoads; };
	City* getStartingPoint() { return _startingPoint; };
	City* getEndPoint() { return _endPoint; };

	void getPairsOfRoadLocation();

	bool isValid(int input) { return (input >= 0 && input <= _numOfCities) ? true : false; };

	eColors* buildCitiesColors();
	Country* buildCountry(eColors* cities);

	int townDistanceRec(Country* country, City* startCity, City* endCity, eColors* colors);
	void townDistanceIter(Country* country, City* startCity, City* endCity, eColors* colors);

	City* getSrcCityNumber() { return _srcCityNumber; }
	City* getDestCityNumber() { return _destCityNumber; }

	bool isValidInput(int inputUser,int from, int to); /*{ return (inputUser >= 0 && inputUser <= _country.getNumOfCities()) ? true : false; }*/
};