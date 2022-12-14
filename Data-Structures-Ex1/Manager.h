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

int const START = 2;
int const AFTER = 3;

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
	void runProgram();
	int townDistanceRec(City* srcCity, City* destCity);
	int townDistanceIter(City* srcCity, City* destCity);
	vector<int> buildCitiesColorsArr();
	void getInputNumberOfCitiesandRoads();
	void getInputSrcAndDest();
	void getPairsOfRoadLocation();
	void buildCountryStructure();
	bool hasWhiteNearbyCities(vector<int> colorCitiesArr, ListNode* currNearbyCity);
	void Func(Stack& Stack, ItemType curr, vector<int> colorCitiesArr, int currCityNumber);
	vector<pair<int, int>> removeDuplicates(vector<pair<int, int>> roadLocation);
	bool isValidInput(int inputUser, int from, int to);
	void printInvalidInput();
	void printResultRec(int res);
	void printResultIter(int res);
	bool isSamePair(vector<pair<int, int>> roadLocation, int from, int to);
};