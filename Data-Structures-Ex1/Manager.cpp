#include "Manager.h"

void Manager::run()
{
	// create Country and City 
	Country* country;

	// get all inputs
	getinputNumberOfCitiesandRoads();
	getinputStartingAndEndPoint();
	getPairsOfRoadLocation();

	//cities = buildCitiesColors();
	//country = buildCountry(cities); // creates an array of LinkedLists from cities

	//townDistanceRec(country, _startingPoint, _endPoint, cities);
}


void Manager::getinputNumberOfCitiesandRoads()
{
	int numberOfCities;
	int numberOfRoads;

	cout << "insert number of cities: ";
	cin >> numberOfCities;

	_numOfCities = numberOfCities;

	cout << "insert number of roads: ";
	cin >> numberOfRoads;

	_numOfRoads = numberOfRoads;
}


void Manager::getinputStartingAndEndPoint()
{
	int startingCityNumber;
	int endCityNumber;

	cout << "Enter number of starting city ";
	cout << " ( between 1 to " << _numOfCities << " ): ";
	cin >> startingCityNumber;

	_startingPoint = new City(startingCityNumber, nullptr);

	cout << "Enter number of end city: ";
	cin >> endCityNumber;

	_endPoint = new City(endCityNumber, nullptr);
}


void Manager::getPairsOfRoadLocation()
{
	int road1, road2;
	cout << "please enter " << _numOfRoads << " pairs of roads: ";

	for (int i = 0; i < _numOfRoads; i++)
	{
		cin >> road1;
		cin >> road2;

		_roadPair.resize(_numOfRoads);

		_roadPair[i].first = road1;
		_roadPair[i].second = road2;

		// for debug
		cout << "pair #" << i << " is: ";
		cout << "< " << _roadPair[i].first << " , " << _roadPair[i].second << " >" << endl;
	}
}

// build cities color array and init every element to white
eColors* Manager::buildCitiesColors()
{
	eColors* citiesColors = new eColors[_country.getNumOfCities()];

	for (int i = 0; i < _country.getNumOfCities(); i++)
	{
		citiesColors[i] = eColors::WHITE;
	}

	return citiesColors;
}

int Manager::townDistanceRec(Country* country, City* startCity, City* endCity, eColors* colors) // todo use colors
{
	// turn statring city to black
	startCity->setColor(0); // black

	// if start=end return 0
	if (startCity == endCity) return 0;

	// no nearby cities return -1
	List* list = startCity->getNearbyCities();
	if (startCity->getNearbyCities()->getHead() == NULL)
		return -1;
	else // we have nearby cities 
	{
		int res;
		City* curr = startCity->getNearbyCities()->getHead();
		while (curr != NULL)
		{
			if (curr->getColor() == 1) // white city
			{
				res = townDistanceRec(country, curr->getNext(), endCity, colors);
				return res != -1 ? res + 1 : -1;
			}
		}
	}
}