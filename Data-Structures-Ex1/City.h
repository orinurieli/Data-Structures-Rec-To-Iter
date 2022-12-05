#pragma once

class List;

class City
{
private:
	int _cityNum;
	int _color;
	List* _nearbyCities;
	City* _nextCity;

public:
	City();
	City(int cityNum, City* nextCity);

	void setCityNumber(int cityNum);
	void setColor(int binary) { _color = binary; }

	int getColor() { return _color; }
	int getCityNumber() const;
	City* getNext() const { return _nextCity; }
	List* getNearbyCities() const;

	void insertNearbyCitiesToSortedList(City* nearbyCity);
};