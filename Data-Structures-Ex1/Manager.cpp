#include "Manager.h"
#include <string>

void Manager::runProgram()
{
	// all inputs & build the country stucture
	getInputNumberOfCitiesandRoads(); // get number of cities and roads from the user
	getPairsOfRoadLocation(); // get pair of road location from the user
	buildCountryStructure(); // creates an array of linked lists from cities
	getInputSrcAndDest(); // get the source and the destination location from the user

	// <Recursive way>
	_colorCitiesRec = buildCitiesColorsArr(); // build cities colors array and init all the cities to white
	int resultRec = townDistanceRec(_country.getCityInCountry(_srcCityNumber), _country.getCityInCountry(_destCityNumber)); // return the favorite distance in recursive way
	printResultRec(resultRec); // print the result of favorite distance

	// <Iterative way>
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
	int nearbyCityNumber, favoriteDistance;

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
					cout << endl << endl << "Before Recurion: call city #" << nearbyCityNumber << endl << endl;
						favoriteDistance = townDistanceRec(_country.getCityInCountry(nearbyCityNumber), destCity);
					cout << endl << endl << "After Recurion: call city #" << nearbyCityNumber << " Favorite Distance: " << favoriteDistance + 1 << endl << endl;
					if (favoriteDistance != NO_PATH)
						return favoriteDistance + 1;
				}
			currNearbyCity = currNearbyCity->getNextCity();
		}
		return NO_PATH;
	}
}

void Manager::Func(Stack& Stack, ItemType curr, vector<int> colorCitiesArr, int currCityNumber)
{
	ListNode* currCity = _country.getCityInCountry(currCityNumber)->getNearbyCities()->getHead();
	while (currCity != nullptr && colorCitiesArr[(currCity->getCityNum() - 1)] == BLACK)
		currCity = currCity->getNextCity();

	if (currCity != nullptr)
	{
		//cout << endl << "We send ";
		//cout << "curr: " << currNode->getCityNum() << endl;
		ItemType next(_country.getCityInCountry(currCity->getCityNum()), currCity->getNextCity(), START, curr.getFavoriteDistance() + 1);
		Stack.Push(next);
	}
}

int Manager::townDistanceIter(City* srcCity, City* destCity)
{
	Stack Stack;

	int srcCityNumber = srcCity->getCityNum();
	int destcitynumber = destCity->getCityNum();
	ListNode* currNearbyCity = srcCity->getNearbyCities()->getHead();
	City* currCity = _country.getCityInCountry(currNearbyCity->getCityNum());
	int returnValue = 0;

	_colorCitiesIter[(srcCityNumber - 1)] = BLACK;

	// base cases
	if (srcCityNumber == destcitynumber)
		return 0;
	if (!hasWhiteNearbyCities(_colorCitiesIter, currNearbyCity))
		return NO_PATH;

	// push data before rec call
	ItemType curr(srcCity, currNearbyCity, START, 0);
	Stack.Push(curr);

	// initiate and push data that get passed to rec call
	ItemType next(currCity, currCity->getNearbyCities()->getHead(), START, curr.getFavoriteDistance() + 1);
	Stack.Push(next);

	// 5 5
	// 1 4 1 2 3 5 2 5 2 3

	while (!Stack.isEmpty())
	{
		curr = Stack.Pop();
		int currCityNumber = curr.getCity()->getCityNum();

		if ((curr.getLine() == START) && (_colorCitiesIter[(currCityNumber - 1)] == WHITE))
		{
			_colorCitiesIter[(currCityNumber - 1)] = BLACK;
			cout << endl << "start city #" << curr.getCity()->getCityNum() << endl;
			if (currCityNumber == destcitynumber)
			{
				cout << endl << "src == dest, top of the stack" << endl;
				returnValue = curr.getFavoriteDistance();
				break;
			}
			else
			{
				curr.setLine(AFTER);
				Stack.Push(curr);
				Func(Stack, curr, _colorCitiesIter, currCityNumber);
			}
		}
		else if (curr.getLine() == AFTER)
		{
			cout << endl << "after city #" << curr.getCity()->getCityNum() << endl;
			cout << endl << "returnvalue: " << returnValue << endl;
		}
		else // we are back to the first element of the stack
		{
			cout << endl << endl << "back to srccity" << endl << endl;

			Func(Stack, curr, _colorCitiesIter, currCityNumber);
			returnValue = curr.getFavoriteDistance() + 1;
			cout << "last returnValue: " << returnValue << endl;
		}
	}

	return returnValue > 0 ? returnValue : NO_PATH;
}

void Manager::getInputNumberOfCitiesandRoads()
{
	int numberOfCities;
	int numberOfRoads;

	cin >> numberOfCities >> numberOfRoads;

	//cout << "Insert number of cities: ";
	//cin >> numberOfCities;
	//cout << "Insert number of roads: ";
	//cin >> numberOfRoads;

	if (numberOfCities > 0 && numberOfRoads > 0)
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

	//cout << "Please enter " << _country.getNumOfRoads() << " pairs of roads: ";

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

	_roadLocation = removeDuplicates(_roadLocation);

	// for testing only
	/*for (int i = 0; i < _roadLocation.size(); i++) {
		cout << _roadLocation[i].first << " ";
		cout << _roadLocation[i].second << endl;
	}*/

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

	//cout << "Enter number of source city ";
	//cout << "(between 1 to " << _country.getNumOfCities() << "): ";
	//cin >> srcCityNumber;

	//cout << "Enter number of destination city ";
	//cout << "(not including " << srcCityNumber << "): ";
	//cin >> destCityNumber;

	if (isValidInput(destCityNumber, 1, _country.getNumOfCities()))
	{
		_srcCityNumber = srcCityNumber;
		_destCityNumber = destCityNumber;
	}
	else
		printInvalidInput();
}

bool Manager::isValidInput(int inputUser, int from, int to)
{
	return inputUser >= from && inputUser <= to;
}

void Manager::printResultRec(int res)
{
	cout << endl << "=====RECURSIVE WAY=====" << endl;
	cout << "Favorite distance:  " << res << endl;
}

void Manager::printResultIter(int res)
{
	cout << endl << "=====ITERATIVE WAY=====" << endl;
	cout << "Favorite distance:  " << res << endl;
}

void Manager::printInvalidInput()
{
	cout << "Invalid input" << endl;
	exit(1);
}

vector<pair<int, int>> Manager::removeDuplicates(vector<pair<int, int>> roadLocation)
{
	for (int i = 0; i < roadLocation.size(); i++)
	{
		for (int j = i + 1; j < roadLocation.size(); j++)
		{
			if (isSamePair(roadLocation, i, j))
			{
				roadLocation.erase(roadLocation.begin() + i);
			}
		}
	}
	return roadLocation;
}

bool Manager::isSamePair(vector<pair<int, int>> roadLocation, int from, int to)
{
	return (roadLocation[from].first == roadLocation[to].first && roadLocation[from].second == roadLocation[to].second) ||
		(roadLocation[from].first == roadLocation[to].second && roadLocation[from].second == roadLocation[to].first);
}