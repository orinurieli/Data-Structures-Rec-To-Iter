#include "Manager.h"


Manager::Manager()
{
	_srcCityNumber = new City();
	_destCityNumber = new City();
}

void Manager::run()
{
	// get all inputs & build the country structure
	getinputNumberOfCitiesandRoads();
	getinputStartingAndEndPoint();
	getPairsOfRoadLocation();
	buildCountryStructure(); // creates an array of LinkedLists from cities

	// <Recursive way>
	//1. buildCitiesColorsArr(); [build cities color and then init all the cities in the country structure as whites]
	//2. townDistanceRec(country, _srcCityNumber, _destCityNumber/*, cities*/); [do the algorithm in recursive way]
	//3. print calculated distance

	// <Iterative way>
	//1. buildCitiesColorsArr(); [build cities color and then init all the cities in the country structure as whites]
	//2. townDistanceIter(country, _srcCityNumber, _destCityNumber/*, cities*/); [do the algorithm in iterative way]
	//3. print calculated distance
}

int* Manager::buildCitiesColorsArr()
{
	int* citiesColorsArr = new int[_country.getNumOfCities()];

	for (int i = 0; i < _country.getNumOfCities(); i++)
	{
		citiesColorsArr[i] = 1; // WHITE = 1, BLACK = 0
	}

	return citiesColorsArr;
}

int Manager::townDistanceRec(Country* country, ListNode* srcCityNumber, ListNode* destCityNumber, int* citiesColorsArr)
{
	// turn statring city to black
	srcCityNumber->setColor(citiesColorsArr[0]); // black

	// if start=end return 0
	if (srcCityNumber == destCityNumber) return 0;

	// no nearby cities return -1
	if (srcCityNumber->getNextCity() == NULL)
		return -1;
	else // we have nearby cities 
	{
		int res;
		ListNode* curr = srcCityNumber;
		while (curr != NULL)
		{
			if (curr->getColor() == citiesColorsArr[1]) // white city
			{
				res = townDistanceRec(country, curr->getNextCity(), destCityNumber, citiesColorsArr);
				return res != -1 ? res + 1 : -1;
			}
		}
	}
	return 0; //need to return value
}

int Manager::townDistanceIter(Country* country, City* srcCityNumber, City* destCityNumber, int* citiesColorsArr)
{
	//TODO: algorithm using stack (ADT)
	return 0; //need to return value
}

void Manager::buildCountryStructure()
{
	//TODO: check input
	_country.initCountryStructure();
	_country.fillCountryStructure(_roadLocation);
}

void Manager::getinputNumberOfCitiesandRoads()
{
	int numberOfCities;
	int numberOfRoads;

	cout << "Insert number of cities: ";
	cin >> numberOfCities;

	_country.setNumOfCities(numberOfCities);

	cout << "Insert number of roads: ";
	cin >> numberOfRoads;

	_country.setNumOfRoads(numberOfRoads);

}

void Manager::getinputStartingAndEndPoint()
{
	int srcCityNumber;
	int destCityNumber;

	cout << "Enter number of source city ";
	cout << "(between 1 to " << _country.getNumOfCities() << "): ";
	cin >> srcCityNumber;

	if (isValidInput(srcCityNumber, 1, _country.getNumOfCities()))
	{
		_srcCityNumber->setCityNum(srcCityNumber);
	}

	cout << "Enter number of destination city ";
	cout << "(between 1 to " << _country.getNumOfCities() << "): ";
	cin >> destCityNumber;

	if (isValidInput(destCityNumber, 1, _country.getNumOfCities()))
	{
		_destCityNumber->setCityNum(destCityNumber);
	}
}

void Manager::getPairsOfRoadLocation()
{
	int road1, road2;
	cout << "please enter " << _country.getNumOfRoads() << " pairs of roads: ";

	for (int i = 0; i < _country.getNumOfRoads(); i++)
	{
		cin >> road1;
		cin >> road2;

		_roadLocation.resize(_country.getNumOfRoads());
		_roadLocation[i].first = road1;
		_roadLocation[i].second = road2;
	}

	_roadLocation = removeDuplicates(_roadLocation);
}

bool Manager::isValidInput(int inputUser, int from, int to)
{
	return inputUser >= from && inputUser <= to;
}

vector<pair<int, int>> Manager::removeDuplicates(vector<pair<int, int>> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i].first == arr[j].first && arr[i].second == arr[j].second)
			{
				arr.erase(arr.begin() + i);
			}
		}
	}
	return arr;
}