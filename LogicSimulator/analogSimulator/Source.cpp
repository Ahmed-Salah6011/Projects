//////C:\Users\Sala7\Desktop\sim.txt
#include <iostream>
#include "AND.h"
#include "DynamicGates.h"
#include "DynamicNodes.h"
#include "Gate.h"
#include "Module.h"
#include "NAND.h"
#include "Node.h"
#include "OR.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;


//void importFile(string path , vector<string> &lines)
//{
//	string line;
//	ifstream file;
//	file.open(path);
//	if (file.is_open())
//	{
//		while (!file.eof())
//		{
//			getline(file, line);
//			lines.push_back(line);
//		}
//		cout << "Imported Sucessfully" << endl;
//		file.close();
//	}
//	else
//	{
//		cout << "Unable to open file" << endl;
//	}
//}
//
//string extractName(string line)
//{
//	if (line.substr(0, 3) == "AND" || line.substr(0, 3) == "XOR" || line.substr(0, 3) == "Set" || line.substr(0, 3) == "Out")
//	{
//		return line.substr(0, 3);
//	}
//	else if (line.substr(0, 2) == "OR")
//	{
//		return line.substr(0, 2);
//	}
//	else if (line.substr(0, 4) == "NAND")
//	{
//		return line.substr(0, 4);
//	}
//}
//
//int secondSpaceIndex(int startIndex, string line)
//{
//	int i; 
//	for (i = startIndex; i < line.length(); i++)
//	{
//		if (line[i] == ' ')
//		{
//			return i;
//		}
//	}
//
//	return i + 1;
//}
//
//void extractNodes(string line, DynamicNodes &nodes,int lineIndex)
//{
//	int first, second;
//	Node n;
//	int flag = line.find(' ');
//	string nodename,bag;
//	for (int i = 0; i<line.length();i++)
//	{
//		if (line[i] == ' ')
//		{
//			first = i;
//			second = secondSpaceIndex(i + 1, line);
//			nodename = line.substr(first+1, second-first-1);
//			if (first ==flag && lineIndex == 0){ bag = nodename; }
//			n.SetName(nodename);
//			nodes.addNode(n);
//			
//		}
//	}
//	if (lineIndex == 0)
//	{
//		n.SetName(bag);
//		nodes.setNode(0, n);
//	}
//}
//
//void handleLines(vector<string> lines, DynamicNodes &nodes, vector<string> &gatenames, int &setIndex)
//{
//	string line;
//	string extraction;
//	for (int i = 0; i < lines.size(); i++)
//	{
//		line = lines[i];
//		extraction = extractName(line);
//		if (extraction == "Set")
//		{
//			setIndex = i;
//			break;
//		}
//		else
//		{
//			gatenames.push_back(extraction);
//			/////
//			extractNodes(line, nodes,i);
//		}
//
//	}
//}
//
//void FillingNodes(int setIndex, int &outIndex, vector<string> lines, DynamicNodes &nodes)
//{
//	string extraction,line;
//	string nodename;
//	int last,value;
//	for (int i = setIndex; i < lines.size(); i++)
//	{
//		line = lines[i];
//		extraction = extractName(line);
//		if (extraction == "Out")
//		{
//			outIndex = i;
//			break;
//		}
//		else
//		{
//			last = line.rfind(' ');
//			if (line.substr(last + 1) == "0"){ value = 0; }
//			else { value = 1; }
//			nodename = line.substr(4, last - 3 - 1);
//			nodes.adjustNode(nodename, value);
//		}
//
//	}
//}
//
//void extractOut(int outIndex, vector<string> &outNodes, vector<string> lines)
//{
//	for (int i = outIndex; i < lines.size(); i++)
//	{
//		outNodes.push_back(lines[i].substr(3));
//	}
//}


int main(){
	//string path;
	//vector<string> lines;
	//DynamicNodes nodes;
	//vector<string> gatenames;
	//vector<string> outNodes;
	//cin >> path;
	//importFile(path, lines);
	///////////////////
	//int setIndex;
	//int outIndex;
	//handleLines(lines, nodes, gatenames, setIndex);
	///////////////
	//FillingNodes(setIndex, outIndex, lines, nodes);
	/////////////
	//extractOut(outIndex, outNodes, lines);
	/////////////

	/*vector<Node> x = m1.getNodes();
	
	for (int i = 0; i < x.size(); i++)
	{
		cout << x[i].getName() << " " << x[i].getValue() << endl;
	}*/

	//vector<string> x = m1.get_outNodes(); 
	/*DynamicNodes x = m1.getNodes();
	m1.Run();
	for (int i = 0; i < x.getSize(); i++)
	{
		cout << x.getNode(i).getName() << "  " << x.getNode(i).getValue() << endl;
	}*/

	/*vector<Gate*> x = m1.getGates();
	m1.Run();
	for (int i = 0; i < x.getSize(; i++)
	{
		cout << x.getGate(i)->getIn1()->getName() << " " << x.getGate(i)->getIn2()->getName() << " " << x.getGate(i)->getOut()->getName()<<endl;
	}*/

	string path;
	cin >> path;
	Module m1(path);
	m1.Run();



////////////C:\Users\Sala7\Desktop\sim.txt
	return 0;
}