#include "XOR.h"


void XOR::calcOut(){
	if ((inp1->getValue() == 1 && inp2->getValue() == 1) || (inp1->getValue() == 0 && inp2->getValue() == 0))
	{
		out->setValue(0);
	}
	else
	{
		out->setValue(1);
	}
}
