#include "AND.h"
#include "Node.h"
#include "Gate.h"
#include <iostream>
using namespace std;


void AND::calcOut(){
	if (inp1->getValue() == 1 && inp2->getValue() == 1)
	{
		out->setValue(1);
	}
	else
	{
		out->setValue(0);
	}
}