#include "Node.h"
#include <iostream>
using namespace std;



void Node::setValue(int n){
	value = n;
}
void Node::SetName(string x){
	Name = x;
}
string Node::getName(){
	return Name;
}
int Node::getValue(){
	return value;
}

