#include "NAND.h"
#include <iostream>
using namespace std;



void NAND::calcOut(){
	if (inp1->getValue() == 1 && inp2->getValue() == 1)
	{
		out->setValue(0);
	}
	else
	{
		out->setValue(1);
	}
}