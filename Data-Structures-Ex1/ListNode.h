#pragma once

class ListNode
{
private:
	int _cityNum;
	int _colorCity = 1; // WHITE
	ListNode* _nextCity;
public:
	//ListNode();
	ListNode(int cityNum = 0, ListNode* nextCity = nullptr);
	void setColorCity(int colorCity) { _colorCity = colorCity; }
	int getColorCity() const { return _colorCity; }
	void setCityNum(int cityNum) { _cityNum = cityNum; }
	int getCityNum() const { return _cityNum; }
	void setNextCity(ListNode* nextCity) { _nextCity = nextCity; }
	ListNode* getNextCity() const { return _nextCity; }
};