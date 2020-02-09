#pragma once
#include "Gate.h"
class DynamicGates
{
public:
	DynamicGates(DynamicGates &x);
	DynamicGates();
	DynamicGates(int news);
	void setSize(int news);
	void setGate(int index, Gate* b);
	Gate* getGate(int index);
	void addGate(Gate* b);
	void insertGate(int index, Gate* b);
	void removeGate(int index);
	int getSize();
private:
	int size;
	Gate** g;

};

