#pragma once
#include "Node.h"
class Gate
{
public:
	void setIn1(Node* n);
	void setIn2(Node* v);
	void setOut(Node* b);
	Node* getOut();
	Node* getIn1();
	Node* getIn2();
	virtual void calcOut()=0;
protected:
	Node* inp1;
	Node* inp2;
	Node* out;
};

