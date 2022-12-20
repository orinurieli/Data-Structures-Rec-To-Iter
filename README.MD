# Data Structure Assignment 

As part of a data structure course, we were asked to implement an algorithm for finding the shortest path between numbered cities, when the path from city to city should be made by having priority to first pass through the city with a lower number.

# Instructions

The assignment includes writing a program in C++ that contains two central functions that implement the TownDistance algorithm.
One function will implement the algorithm as it is described (in a recursive form) and the other will implement it without
Using recursion.


## Example
- Looking at the drawing - for the Src city 2 and Dest city 5, the preferred distance is 2. 
- The reason is that city 2 has 3 cities
Neighborhoods: 5,3,1. From city 1 there is no way to reach 5, and from city 3 the road to city 5 is 2 long. 
- Therefore, the preferred route from 2 to 5 is 2-3-5, and the number of transitions in this route is 2.

- (https://drive.google.com/file/d/16GmEHsr8btcweGmmvtC_ZS6UO5klSq2H/view?usp=share_link)[]!

## Recursive Way
```cpp
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

```

## Turn Rec To Iter
- We now want to take this Recursive code, and turn it to Iterative one.
1. implement a Stack with data of type ItemType.
2. Use While loop that continues until we have reached the original stopping condition of the recursion.
3. Use the Stack to save the value of the local variables, the parameters that are passed
to recursion, and the line to which you need to return.


## Iterative Way

```cpp
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

```


## Project Goals

- Using Data Structures
- Working with OOP principles
- Understand a transition from recursion to iterative

##### Made by [Gal Swid](https://github.com/GalSwid) & [Ori Nurieli](https://github.com/orinurieli)  
