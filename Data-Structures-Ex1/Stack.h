#pragma once
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
	int _top; // index above top item
	vector<int> _data;

public:
	Stack();
	~Stack();

	void makeEmpty();
	int isEmpty();
	int isFull();

	void Push(int item);
	void Pop();
	void Top();
};