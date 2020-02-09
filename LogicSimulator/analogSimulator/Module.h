#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "DynamicNodes.h"
#include "DynamicGates.h"
#include "Node.h"
#include "AND.h"
#include "OR.h"
#include "NAND.h"
#include "XOR.h"

using namespace std;

class Module
{
public:
	Module(string path);
	vector<string> getLines();
	vector<Node> getNodes();
	vector<Gate*> getGates();
	vector<string> get_gateNames();
	vector<string> get_outNodes();
	void Run();
private:
	///////members
	ifstream file;
	vector<string> lines;
	vector<Node> nodes;
	vector<Gate*> gates;
	vector<string> gatenames;
	vector<string> OutNodes;
	int setIndex;
	int outIndex;
	vector<string> nodenames;
	////////functions
	void handleLines();
	string extractName(string line);
	void extractNodes(string line);
	int secondSpaceIndex(int startIndex, string line);
	void FillingNodes();
	void extractOut();
	void ImportFile(string path);
	void FillingGates();
	int FindNodeName(string name);
	bool Node_isIn(string nodename);
};

