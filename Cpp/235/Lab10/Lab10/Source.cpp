#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"QuickSort.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[]) {

	VS_MEM_CHECK

	if (argc < 3)
	{
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	QuickSort<int> qSort;

	string full_line;
	while (getline(in, full_line)) {
		istringstream inSS(full_line);
		string command;
		inSS >> command;
		if (command == "QuickSort") {
			int newCapacity = 0;
			inSS >> newCapacity;
			qSort.createArray(newCapacity);
			out << full_line << " OK" << endl;
		}
		if (command == "Capacity") {
			int capacity_ = 0;
			capacity_ = qSort.capacity();
			out << full_line << " " << capacity_ << endl;
		}
		if (command == "Clear") {
			qSort.clear();
			out << full_line << " OK" << endl;
			//qSort.createArray(7);
		}
		if (command == "AddToArray") {
			int addNum = 0;
			//out << command << " ";
			ostringstream toP;
			while (inSS >> addNum) {
				toP << addNum << ",";
				qSort.addElement(addNum);
			}
			string printMe = toP.str();
			printMe = printMe.substr(0, printMe.size() - 1);
			out << command << "  " << printMe << " OK" << endl;
		}
		if (command == "Size") {
			int size_ = qSort.size();
			out << command << " " << size_ << endl;
		}
		if (command == "PrintArray") {
			string pArray = qSort.toString();
			out << command << " " << pArray << endl;
		}
		if (command == "MedianOfThree") {
			int left = 0;
			inSS >> left;
			int right = 0;
			inSS >> right;
			int middle = qSort.medianOfThree(left, right);
			out << command << " " << left << "," << right << " = " << middle << endl;
		}
		if (command == "Partition") {
			int left = 0;
			inSS >> left;
			int right = 0;
			inSS >> right;
			int part = 0;
			inSS >> part;
			int middle = qSort.partition(left, right, part);
			out << command << " " << left << "," << right << "," << part << " = " << middle << endl;
		}
		if (command == "SortAll") {
			qSort.sortAll();
			out << command << " OK" << endl;
		}
		if (command == "Sort") {
			int left = 0;
			inSS >> left;
			int right = 0;
			inSS >> right;
			qSort.sort(left, right);
			out << command << " " << left << "," << right << " OK" << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}