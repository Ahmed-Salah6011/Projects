#include "Gate.h"
#include <iostream>
using namespace std;


void Gate::setIn1(Node* n){
	inp1 = n;
}
void Gate::setIn2(Node* v){
	inp2 = v;
}
Node* Gate::getOut(){
	return out;
}

void Gate::setOut(Node* b){
	out = b;
}

Node* Gate::getIn1(){
	return inp1;
}
Node* Gate::getIn2(){
	return inp2;
}

