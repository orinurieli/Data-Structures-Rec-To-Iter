#include "Manager.h"
#include <string>

void Manager::runProgram()
{
	// all inputs & build the country stucture
	getInputNumberOfCitiesandRoads(); // get number of cities and roads from the user
	getPairsOfRoadLocation(); // get pair of road location from the user
	buildCountryStructure(); // creates an array of linked lists from cities
	getInputSrcAndDest(); // get the source and the destination location from the user

	// <recursive algorithm>
	_colorCitiesRec = buildCitiesColorsArr(); // build cities colors array and init all the cities to white
	int resultRec = townDistanceRec(_country.getCityInCountry(_srcCityNumber), _country.getCityInCountry(_destCityNumber)); // return the favorite distance in recursive way
	printResultRec(resultRec); // print the result of favorite distance

	// <iterative stack algorithm>
	_colorCitiesIter = buildCitiesColorsArr(); // build cities colors array and init all the cities to white
	int resultIter = townDistanceIter(_country.getCityInCountry(_srcCityNumber), _country.getCityInCountry(_destCityNumber)); // return the favorite distance in iterative way
	printResultIter(resultIter); // print the result of favorite distance
}

vector<int> Manager::buildCitiesColorsArr()
{
	vector<int> citiesColorsArr;

	for (int i = 0; i < _country.getNumOfCities(); i++)
	{
		citiesColorsArr.push_back(WHITE);
	}

	return citiesColorsArr;
}

bool Manager::hasWhiteNearbyCities(vector<int> colorCitiesArr, ListNode* currNearbyCity)
{
	int nearbyCityNumber;

	while (currNearbyCity != nullptr)
	{
		nearbyCityNumber = currNearbyCity->getCityNum();
		if (colorCitiesArr[(nearbyCityNumber - 1)] == WHITE)
			return true;

		currNearbyCity = currNearbyCity->getNextCity();
	}
	return false;
}

int Manager::townDistanceRec(City* srcCity, City* destCity)
{
	int srcCityNumber = srcCity->getCityNum();
	int destCityNumber = destCity->getCityNum();
	ListNode* currNearbyCity = srcCity->getNearbyCities()->getHead();
	int nearbyCityNumber, preferreDistance;

	_colorCitiesRec[(srcCityNumber - 1)] = BLACK;

	if (srcCityNumber == destCityNumber)
		return 0;
	else if (!hasWhiteNearbyCities(_colorCitiesRec, currNearbyCity))
		return NO_PATH;
	else
	{
		while (currNearbyCity != nullptr)
		{
			nearbyCityNumber = currNearbyCity->getCityNum();
			if (_colorCitiesRec[(nearbyCityNumber - 1)] == WHITE)
			{
				preferreDistance = townDistanceRec(_country.getCityInCountry(nearbyCityNumber), destCity);
				if (preferreDistance != NO_PATH)
					return preferreDistance + 1;
			}
			currNearbyCity = currNearbyCity->getNextCity();
		}
		return NO_PATH;
	}
}

void Manager::firstWhiteNearbyCitySTART(Stack& Stack, ItemType curr, vector<int> colorCitiesArr, int currCityNumber)
{
	ListNode* currCity = _country.getCityInCountry(currCityNumber)->getNearbyCities()->getHead();

	while (currCity != nullptr && colorCitiesArr[(currCity->getCityNum() - 1)] == BLACK)
		currCity = currCity->getNextCity();

	if (currCity != nullptr)
	{
		Stack.Push(curr);
		ItemType next(_country.getCityInCountry(currCity->getCityNum()), 
					  _country.getCityInCountry(currCity->getCityNum())->getNearbyCities()->getHead(),
					  START, curr.getPreferreDistance() + 1);
		Stack.Push(next);
	}
}

void Manager::firstWhiteNearbyCityAFTER(Stack& Stack, ItemType curr, vector<int> colorCitiesArr, int currCityNumber)
{
	ListNode* currCity = _country.getCityInCountry(currCityNumber)->getNearbyCities()->getHead();

	while (currCity != nullptr && colorCitiesArr[(currCity->getCityNum() - 1)] == BLACK)
		currCity = currCity->getNextCity();

	if (currCity != nullptr)
	{
		Stack.Push(curr);
		ItemType next(_country.getCityInCountry(currCity->getCityNum()),
			_country.getCityInCountry(currCity->getCityNum())->getNearbyCities()->getHead(),
			START, curr.getPreferreDistance() + 1);
		Stack.Push(next);
	}
}

int Manager::townDistanceIter(City* srcCity, City* destCity)
{
	Stack Stack;

	int srcCityNumber = srcCity->getCityNum();
	int destcitynumber = destCity->getCityNum();
	ListNode* currNearbyCity = srcCity->getNearbyCities()->getHead();
	int returnValue = NO_PATH;

	// base case
	if (srcCityNumber == destcitynumber)
		return 0;
	if (!hasWhiteNearbyCities(_colorCitiesIter, currNearbyCity))
		return NO_PATH;

	// push data before rec call
	ItemType curr(srcCity, currNearbyCity, START, 0);
	Stack.Push(curr);

	while (!Stack.isEmpty())
	{
		curr = Stack.Pop();

		int currCityNumber = curr.getCity()->getCityNum();
		ListNode* currNearbyCity = curr.getCity()->getNearbyCities()->getHead();

		if ((curr.getLine() == START) && (_colorCitiesIter[(currCityNumber - 1)] == WHITE))
		{
			_colorCitiesIter[(currCityNumber - 1)] = BLACK;

			if (currCityNumber == destcitynumber)
			{
				returnValue = curr.getPreferreDistance();
				break;
			}
			else
			{
				curr.setLine(AFTER);
				Stack.Push(curr);
				firstWhiteNearbyCitySTART(Stack, curr, _colorCitiesIter, currCityNumber);
			}
		}
		else if (curr.getLine() == AFTER)
		{
			firstWhiteNearbyCityAFTER(Stack, curr, _colorCitiesIter, currCityNumber);
		}
	}

	return returnValue;
}

void Manager::getInputNumberOfCitiesandRoads()
{
	int numberOfCities;
	int numberOfRoads;

	cin >> numberOfCities >> numberOfRoads;

	if (numberOfCities > 1 && numberOfRoads > 0)
	{
		_country.setNumOfCities(numberOfCities);
		_country.setNumOfRoads(numberOfRoads);
	}
	else
		printInvalidInput();
}

void Manager::getPairsOfRoadLocation()
{
	int roadA, roadB;

	for (int i = 0; i < _country.getNumOfRoads(); i++)
	{
		cin >> roadA;
		cin >> roadB;

		if (!isValidInput(roadA, 1, _country.getNumOfCities()) || !isValidInput(roadB, 1, _country.getNumOfCities()) || roadA == roadB)
		{
			printInvalidInput();
		}
		else
			_roadLocation.push_back({ roadA, roadB });
	}

	if (_roadLocation.size() != _country.getNumOfRoads() || hasDuplicatePair(_roadLocation))
		printInvalidInput();
}

void Manager::buildCountryStructure()
{
	_country.initCountry();
	_country.createCountry(_roadLocation);
}

void Manager::getInputSrcAndDest()
{
	int srcCityNumber;
	int destCityNumber;

	cin >> srcCityNumber >> destCityNumber;

	if (!isValidInput(srcCityNumber, 1, _country.getNumOfCities()) || !isValidInput(destCityNumber, 1, _country.getNumOfCities()))
		printInvalidInput();
	else
	{
		_srcCityNumber = srcCityNumber;
		_destCityNumber = destCityNumber;
	}
}

bool Manager::hasDuplicatePair(vector<pair<int, int>> roadLocation)
{
	for (int i = 0; i < roadLocation.size(); i++)
	{
		for (int j = i + 1; j < roadLocation.size(); j++)
		{
			if (isSamePair(roadLocation, i, j))
			{
				return true;
			}
		}
	}
	return false;
}

bool Manager::isSamePair(vector<pair<int, int>> roadLocation, int from, int to)
{
	return (roadLocation[from].first == roadLocation[to].first && roadLocation[from].second == roadLocation[to].second) ||
		(roadLocation[from].first == roadLocation[to].second && roadLocation[from].second == roadLocation[to].first);
}

bool Manager::isValidInput(int inputUser, int from, int to)
{
	return inputUser >= from && inputUser <= to;
}

void Manager::printResultRec(int res)
{
	cout << "Preferred distance (recursive algorithm): " << res << endl;
}

void Manager::printResultIter(int res)
{
	cout << "Preferred distance (iterative stack algorithm): " << res << endl;
}

void Manager::printInvalidInput()
{
	cout << "invalid input" << endl;
	exit(1);
}
