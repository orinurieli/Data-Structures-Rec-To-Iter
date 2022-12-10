#pragma once

class ListNode
{
private:
	int _cityNum;
	ListNode* _nextCity;

public:
	ListNode(int cityNum = 0, ListNode* nextCity = nullptr);
	void setCityNum(int cityNum) { _cityNum = cityNum; }
	int getCityNum() const { return _cityNum; }
	void setNextCity(ListNode* nextCity) { _nextCity = nextCity; }
	ListNode* getNextCity() const { return _nextCity; }
};