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
	int resultRec = townDistanceRec(_country.getCityInCountry(_srcCityNumber), _country.getCityInCountry(_destCityNumber), _colorCitiesRec); // return the favorite distance in recursive way
	printResultRec(resultRec); // print the result of favorite distance

	// <Iterative way>
	_colorCitiesIter = buildCitiesColorsArr(); // build cities colors array and init all the cities to white
	int resultIter = townDistanceIter(_country.getCityInCountry(_srcCityNumber), _country.getCityInCountry(_destCityNumber), _colorCitiesIter); // return the favorite distance in iterative way
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
		if (colorCitiesArr[nearbyCityNumber - 1] == WHITE)
			return true;

		currNearbyCity = currNearbyCity->getNextCity();
	}
	return false;
}

int Manager::townDistanceRec(City* srcCity, City* destCity, vector<int> colorCitiesArr)
{
	int srcCityNumber = srcCity->getCityNum();
	int destCityNumber = destCity->getCityNum();
	List* nearbyCities = srcCity->getNearbyCities();
	ListNode* currNearbyCity = nearbyCities->getHead();
	int nearbyCityNumber, favoriteDistance;

	colorCitiesArr[srcCityNumber - 1] = BLACK;

	if (srcCityNumber == destCityNumber)
		return 0;
	else
	{
		if (!hasWhiteNearbyCities(colorCitiesArr, currNearbyCity))
			return NO_PATH;
		else
		{
			// 5 5
			// 1 4 1 2 3 5 2 5 2 3

			while (currNearbyCity != nullptr)
			{
				nearbyCityNumber = currNearbyCity->getCityNum();
				if (colorCitiesArr[nearbyCityNumber - 1] == WHITE)
				{
					//cout << endl << endl << "Before Recurion: city #" << nearbyCityNumber << endl << endl;
					favoriteDistance = townDistanceRec(_country.getCityInCountry(nearbyCityNumber), destCity, colorCitiesArr);
					//cout << endl << endl << "After Recurion: city #" << nearbyCityNumber << " Favorite Distance: " << favoriteDistance + 1 << endl << endl;
					if (favoriteDistance != NO_PATH)
					{ 
						//cout << endl << endl << "After Recurion: city #" << nearbyCityNumber << " Favorite Distance: " << favoriteDistance + 1 << endl << endl;
						return favoriteDistance + 1;
					}
				}
				currNearbyCity = currNearbyCity->getNextCity();
			}
			return NO_PATH;
		}
	}
}

int Manager::townDistanceIter(City* srcCity, City* destCity, vector<int> colorCitiesArr)
{
	Stack Stack;

	int srcCityNumber = srcCity->getCityNum();
	int destCityNumber = destCity->getCityNum();

	List* nearbyCities = srcCity->getNearbyCities();
	ListNode* currNearbyCity = nearbyCities->getHead();
	int nearbyCityNumber = currNearbyCity->getCityNum(), favoriteDistance = NO_PATH;
	City* currCity = _country.getCityInCountry(nearbyCityNumber);

	int returnValue = 0;

	colorCitiesArr[srcCityNumber - 1] = BLACK;

	// base cases
	if (srcCity == destCity) return 0;
	if (!hasWhiteNearbyCities(colorCitiesArr, currNearbyCity))
		return NO_PATH;

	// push data before rec call
	ItemType curr(srcCity, currNearbyCity, START, 0);
	Stack.Push(curr);

	// initiate and push data that get passed to rec call
	ItemType next(currCity, currCity->getNearbyCities()->getHead(), START, curr.getFavoriteDistance() + 1);
	Stack.Push(next);

	while (!Stack.isEmpty())
	{
		curr = Stack.Pop();
		if (curr.getLine() == START && colorCitiesArr[curr.getCity()->getCityNum() - 1] == WHITE)
		{
			colorCitiesArr[curr.getCity()->getCityNum() - 1] = BLACK;
			cout << endl << "START City #" << curr.getCity()->getCityNum() << endl;
			if (curr.getCity()->getCityNum() == destCity->getCityNum())
			{
				cout << endl << "src == dest, top of the Stack" << endl;
				returnValue = curr.getFavoriteDistance();
				break;
			}
			else {
				curr.setLine(AFTER);
				Stack.Push(curr);

				ListNode* currNode = _country.getCityInCountry(curr.getCity()->getCityNum())->getNearbyCities()->getHead();
				while (currNode != NULL && colorCitiesArr[currNode->getCityNum() - 1] == BLACK)
					currNode = currNode->getNextCity();

				if (currNode != NULL) {
					cout << endl << "We send ";
					cout << "curr: " << currNode->getCityNum() << endl;
					ItemType next(_country.getCityInCountry(currNode->getCityNum()), currNode->getNextCity(), START, curr.getFavoriteDistance() + 1);
					Stack.Push(next);
				}
			}
		}

		else if (curr.getLine() == AFTER)
		{
			cout << endl << "AFTER City #" << curr.getCity()->getCityNum() << endl;
			cout << endl << "returnValue: " << returnValue << endl;
		}
		else // we are back to the first element of the Stack
		{
			cout << endl << endl << "Back to SrcCity" << endl << endl;

			ListNode* currNode = _country.getCityInCountry(curr.getCity()->getCityNum())->getNearbyCities()->getHead(); // 2
			while (currNode != NULL && colorCitiesArr[currNode->getCityNum() - 1] == BLACK)
				currNode = currNode->getNextCity();

			if (currNode != NULL) {
				cout << endl << "last currNode: " << currNode->getCityNum() << endl;
				ItemType next(_country.getCityInCountry(currNode->getCityNum()), currNode->getNextCity(), START, curr.getFavoriteDistance() + 1);
				Stack.Push(next);
			}

			returnValue = curr.getFavoriteDistance() + 1;
			cout << "last returnValue: " << returnValue << endl;
		}
	}


	if (returnValue > 0) return returnValue;
	else return NO_PATH;
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