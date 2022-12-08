#pragma once
#include <iostream>
#include <vector>
#include "Country.h"
#include "City.h"
#include "Stack.h"
#include "List.h"

using namespace std;

int const WHITE = 0;
int const BLACK = 1;
int const NO_PATH = -1;

class Manager
{
private:
	Country _country;
	vector<pair<int, int>> _roadLocation;
	vector<int> _colorCitiesRec;
	vector<int> _colorCitiesIter;
	int _srcCityNumber = 0;
	int _destCityNumber = 0;

public:
	void run();

	int townDistanceRec(City* srcCity, City* destCity, vector<int> colorCitiesArr);
	int townDistanceIter(City* srcCity, City* destCity, vector<int> colorCitiesArr);

	vector<int> buildCitiesColorsArr();
	void getInputNumberOfCitiesandRoads();
	void getInputSrcAndDest();
	void getPairsOfRoadLocation();
	void buildCountryStructure();
	bool hasWhiteNearbyCities(vector<int> colorCitiesArr, ListNode* currNearbyCity);

	//void setSrcCityNumber(int srcCityNumber) { _srcCityNumber = srcCityNumber; }
	//id setDestCityNumber(int destCityNumber) { _destCityNumber = destCityNumber; }
	//int getSrcCityNumber() { return _srcCityNumber; }
	//int getDestCityNumber() { return _destCityNumber; }
	//vector<int> getColorCitiesArr() { return _colorCitiesRec; }

	vector<pair<int, int>> removeDuplicates(vector<pair<int, int>> roadLocation);
	bool isValidInput(int inputUser, int from, int to);
	void printInvalidInput();
	void printResultRec(int res);
	void printResultIter(int res);
};