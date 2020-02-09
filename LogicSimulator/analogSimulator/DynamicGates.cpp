#include "DynamicGates.h"
#include <iostream>
using namespace std;

DynamicGates::DynamicGates(DynamicGates &x){

	size = x.size;
	if (size>0) {
		g = new Gate*[size];
		for (int i = 0; i < size; i++) {
			g[i] = x.g[i];
		}
	}
	else {
		g = NULL;
	}
}

int DynamicGates::getSize(){
	return size;
}

DynamicGates::DynamicGates(){
	size = 0;
	g = NULL;
}

DynamicGates::DynamicGates(int news){
	size = news;
	g = new Gate*[size];
}

void DynamicGates::setSize(int news){
	if (size == 0)
	{
		size = news;
		g = new Gate*[size];
	}
	else
	{
		Gate** A = new Gate*[news];
		int min = (size < news) ? size : news;
		for (int i = 0; i < min; i++)
		{
			A[i] = g[i];
		}
		delete[] g;
		g = A;
		size = news;
	}
}

void DynamicGates::setGate(int index, Gate* b){
	g[index] = b;
}

Gate* DynamicGates::getGate(int index){
	return g[index];
}

void DynamicGates::addGate(Gate* b){
	if (size == 0)
	{
		size +=1;
		g = new Gate*[size];
		g[0] = b;
	}
	else
	{
		Gate* * A = new Gate*[size + 1];
		for (int i = 0; i < size; i++)
		{
			A[i] = g[i];
		}
		A[size] = b;
		delete[] g;
		g = A;
		size += 1;
	}
}

void DynamicGates::insertGate(int index, Gate* b){
	Gate** A = new Gate*[size + 1];
	for (int i = 0; i < index; i++)
	{
		A[i] = g[i];
	}
	A[index] = b;
	for (int j = index + 1; j <= size; j++)
	{
		A[j] = g[j - 1];
	}
	delete[] g;
	g = A;
	size += 1;
}

void DynamicGates::removeGate(int index){
	Gate** A = new Gate*[size - 1];
	for (int i = 0; i < index; i++)
	{
		A[i] = g[i];
	}
	for (int j = index; j < size - 1; j++)
	{
		A[j] = g[j + 1];
	}
	delete[] g;
	g = A;
	size -= 1;
}