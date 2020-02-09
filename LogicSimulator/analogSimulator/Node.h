#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	void setValue(int n);
	void SetName(string x);
	string getName();
	int getValue();
private:
	string Name;
	int value;
};

