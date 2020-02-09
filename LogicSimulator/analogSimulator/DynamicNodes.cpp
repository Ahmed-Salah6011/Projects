#include "DynamicNodes.h"
#include <iostream>
using namespace std;


DynamicNodes::DynamicNodes(DynamicNodes &x)
{
	size = x.size;
	if (size>0) {
		p = new Node[size];
		for (int i = 0; i < size; i++) {
			p[i] = x.p[i];
		}
	}
	else {
		p = NULL;
	}
}

DynamicNodes::DynamicNodes(){
	p = NULL;
	size = 0;
}

DynamicNodes::DynamicNodes(int news){
		size = news;
		p = new Node[size];
}
DynamicNodes::~DynamicNodes(){
	delete[] p;
}

void DynamicNodes::setSize(int newsize)
{
	if (size == 0)
	{
		size = newsize;
		p = new Node[size];
	}
	else
	{
		Node* A = new Node[newsize];
		int min = (newsize < size) ? newsize : size;
		for (int i = 0; i < min; i++)
		{
			A[i] = p[i];
		}
		delete[] p;
		p = A;
		size = newsize;
	}
}

void DynamicNodes::setPointer(Node* q){
	p = q;
}

int DynamicNodes::getSize(){
	return size;
}
Node* DynamicNodes::getPointer(){
	return p;
}

void DynamicNodes::setNode(int index, Node n){
	p[index] = n;
}

Node DynamicNodes::getNode(int i){
	return p[i];
}

void DynamicNodes::addNode(Node n){
	if (size == 0)
	{
		size +=1;
		p = new Node[size];
		p[0] = n;
	}
	else
	{
		Node* A = new Node[size + 1];
		for (int i = 0; i < size; i++)
		{
			A[i] = p[i];
		}
		A[size] = n;
		delete[] p;
		p = A;
		size += 1;
	}
}

void DynamicNodes::insertNode(int index, Node n){
	Node* A = new Node[size + 1];
	for (int i = 0; i < index; i++)
	{
		A[i] = p[i];
	}
	A[index] = n;
	for (int j = index + 1; j <= size; j++)
	{
		A[j] = p[j - 1];
	}
	delete[] p;
	p = A;
	size += 1;
}

Node DynamicNodes::getNode(string name)
{
	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == name)
		{
			return p[i];
		}
	}
}

void DynamicNodes::adjustNode(string name,int value){
	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == name)
		{
			p[i].setValue(value);
		}
	}
}

void DynamicNodes::adjustNode(int index, int value){
	p[index].setValue(value);
}

void DynamicNodes::removeNode(int index){
	Node* A = new Node[size - 1];
	for (int i = 0; i < index; i++)
	{
		A[i] = p[i];
	}
	for (int j = index; j < size - 1; j++)
	{
		A[j] = p[j + 1];
	}
	delete[] p;
	p = A;
	size -= 1;
}

void DynamicNodes::removeNode(string name){
	///
	int index;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == name)
		{
			index = i;
			break;
		}
	}
	///
	Node* A = new Node[size - 1];
	for (int i = 0; i < index; i++)
	{
		A[i] = p[i];
	}
	for (int j = index; j < size - 1; j++)
	{
		A[j] = p[j + 1];
	}
	delete[] p;
	p = A;
	size -= 1;
}