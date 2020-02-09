#include "Module.h"
#include <iostream>
#include <fstream>
#include "Node.h"
using namespace std;

Module::Module(string path){
	ImportFile(path);

	handleLines();
	FillingNodes();
	extractOut();
	FillingGates();

}

void Module::ImportFile(string path){
	string line;
	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			lines.push_back(line);
		}
		cout << "Imported Sucessfully" << endl;
		file.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}

string Module::extractName(string line){
	if (line.substr(0, 3) == "AND" || line.substr(0, 3) == "XOR" || line.substr(0, 3) == "Set" || line.substr(0, 3) == "Out")
	{
		return line.substr(0, 3);
	}
	else if (line.substr(0, 2) == "OR")
	{
		return line.substr(0, 2);
	}
	else if (line.substr(0, 4) == "NAND")
	{
		return line.substr(0, 4);
	}
}

int Module::secondSpaceIndex(int startIndex, string line)
{
	int i;
	for (i = startIndex; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			return i;
		}
	}

	return i + 1;
}

bool Module::Node_isIn(string nodename){
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].getName() == nodename)
		{
			return true;
		}
	}
	return false;
}


void Module::extractNodes(string line){
	int first, second;
	Node n;
	int flag = line.find(' ');
	string nodename, bag;
	for (int i = 0; i<line.length(); i++)
	{
		if (line[i] == ' ')
		{
			first = i;
			second = secondSpaceIndex(i + 1, line);
			nodename = line.substr(first + 1, second - first - 1);
			nodenames.push_back(nodename);
			if (!Node_isIn(nodename))
			{
				n.SetName(nodename);
				nodes.push_back(n);
			}

		}
	}
}


void Module::handleLines(){
	string line;
	string extraction;
	for (int i = 0; i < lines.size(); i++)
	{
		line = lines[i];
		extraction = extractName(line);
		if (extraction == "Set")
		{
			setIndex = i;
			break;
		}
		else
		{
			gatenames.push_back(extraction);
			if (extraction == "AND")
			{
				gates.push_back(new AND);
			}
			else if (extraction == "OR")
			{
				gates.push_back(new OR);
			}
			else if (extraction == "NAND")
			{
				gates.push_back(new NAND);
			}
			else if (extraction == "XOR")
			{
				gates.push_back(new XOR);
			}
			/////
			extractNodes(line);
		}

	}
}


int Module::FindNodeName(string name){
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i].getName() == name)
		{
			return i;
		}
	}
}


void Module::FillingNodes(){
	string extraction, line;
	string nodename;
	int last, value;
	for (int i = setIndex; i < lines.size(); i++)
	{
		line = lines[i];
		extraction = extractName(line);
		if (extraction == "Out")
		{
			outIndex = i;
			break;
		}
		else
		{
			last = line.rfind(' ');
			if (line.substr(last + 1) == "0"){ value = 0; }
			else { value = 1; }
			nodename = line.substr(4, last - 3 - 1);
			nodes[FindNodeName(nodename)].setValue(value);

		}

	}
}

void Module::extractOut()
{
	for (int i = outIndex; i < lines.size(); i++)
	{
		OutNodes.push_back(lines[i].substr(4));
	}
}


vector<string> Module::getLines(){
	return lines;
}

vector<Node> Module::getNodes(){
	return nodes;
}
vector<Gate*> Module::getGates(){
	return gates;
}

vector<string> Module::get_gateNames(){
	return gatenames;
}

vector<string> Module::get_outNodes(){
	return OutNodes;
}


void Module::FillingGates(){
	
//////
	//
	int index;
	int in1 = 0, in2 = 1, out = 2;
	for (int i = 0; i < gatenames.size(); i++)
	{
		//
		index = FindNodeName(nodenames[in1]);
		gates[i]->setIn1(&nodes[index]);
		//
		index = FindNodeName(nodenames[in2]);
		gates[i]->setIn2(&nodes[index]);
		//
		index = FindNodeName(nodenames[out]);
		gates[i]->setOut(&nodes[index]);
		//
		in1 += 3;
		in2 += 3;
		out += 3;

	}




}

void Module::Run()
{
	for (int i = 0; i < gates.size(); i++)
	{
		gates[i]->calcOut();
	}
	/////////
	int ind;
	for (int j = 0; j < OutNodes.size(); j++)
	{
		ind = FindNodeName(OutNodes[j]);
		cout << nodes[ind].getName() << " " << nodes[ind].getValue()<<endl;
	}

}

