#pragma once
#include "Node.h"
class DynamicNodes
{
public:
	DynamicNodes();
	DynamicNodes(DynamicNodes &x);
	DynamicNodes(int news);
	~DynamicNodes();
	void setSize(int newsize);
	void setPointer(Node* q);
	int getSize();
	Node* getPointer(); 
	void setNode(int index, Node n);
	Node getNode(int i);
	Node getNode(string name);
	void addNode(Node n);
	void insertNode(int index, Node n);
	void removeNode(int index);
	void removeNode(string name);
	void adjustNode(string name, int value);
	void adjustNode(int index, int value);

private:
	int size;
	Node* p;
};

