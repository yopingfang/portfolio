/*
*CS 235
*Summer 2018
*Dr. Stephens
*Section 1
*July 31
*RJ
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "BST.h"

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[])
{
	VS_MEM_CHECK
	
	//Check that there are 3 command lines 
	if (argc < 3)
	{
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	//Open the input file with argv[1]
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	//Open the output file with argv[2]
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	//Create a binary search tree object called tree
	BST<int> tree;

	//Grab each line of the input file one by one until we've gotten all of them
	for (string line; getline(in, line);)
	{
		stringstream ss(line);
		string command;
		ss >> command;
		if (command == "Add")
		{
			int value;
			ss >> value;
			//Call BST addNode function and pass in the given value
			bool added = tree.addNode(value);
			if (added)
				out << line << " True" << endl;
			else
				out << line << " False" << endl;
		}
		else if (command == "PrintBST")
		{
			//Use the insertion operator << which we overrode in the BST class 
			//to output the contents of the binary search tree
			out << line << tree << endl;
		}
		else if (command == "Remove")
		{
			int value;
			ss >> value;
			//Call the BST removeNode function and pass in the given value
			bool removed = tree.removeNode(value);
			if (removed)
				out << line << " True" << endl;
			else
				out << line << " False" << endl;
		}
		else if (command == "Clear")
		{
			//Call the BST clear function and pass in the given value
			bool cleared = tree.clearTree();
			if (cleared)
				out << line << " True" << endl;
			else
				out << line << " False" << endl;
		}
		else if (command == "Tree")
		{
			out << "Tree: ";
			int counter = 0;
			for (BST<int>::Iterator iter = tree.begin(); iter != tree.end(); ++iter)
			{
				out << " " << *iter;
				counter++;
			}
			if (counter == 0)
				out << " Empty";
			out << endl;
		}
		else if (command == "Find")
		{
			int item;
			ss >> item;
			bool found = false;

			for (BST<int>::Iterator iter = tree.begin(); iter != tree.end(); ++iter)
			{
				if (*iter == item)
				{
					out << line << " Found " << item << endl;
					found = true;
				}
			}
			if (!found)
				out << line << " Not Found" << endl;
		}
	}

	in.close();
	out.close();
	return 0;

}