#pragma once

class ListNode
{
private:
	int _cityNum;
	ListNode* _nextCity;
public:
	ListNode();
	ListNode(int cityNum, ListNode* nextCity = nullptr);
	int getCityNum() const { return _cityNum; }
	ListNode* getNextCity() const { return _nextCity; }
};