#include "OR.h"
#include <iostream>
using namespace std;


void OR::calcOut(){
	if (inp1->getValue() == 0 && inp2->getValue() == 0)
	{
		out->setValue(0);
	}
	else
	{
		out->setValue(1);
	}
}