//Created by pp
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include"LinkedList.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

int main(int argc, char *argv[]) {
	
	VS_MEM_CHECK;

	if (argc < 3) {
		cerr << "Please provide name of input and output files";
		return 1;
	}

	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input.";
		return 2;
	}

	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output.";
		return 3;
	}

	LinkedList<int> liList;
	LinkedList<string> lsList;
	string type;
	in >> type;
	if (type == "INT") {
		out << type << " [INT]" << endl;
	}
	if (type == "STRING") {
		out << type << " [STRING]" << endl;
	}
	while (!in.eof()) {
		string command;
		in >> command;
		if (type == "INT") {
			bool isSuccessful;
			int newInfo;
			if (command == "insertHead") {
				in >> newInfo;
				isSuccessful = liList.insertHead(newInfo);
				out << command << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "insertTail") {
				in >> newInfo;
				isSuccessful = liList.insertTail(newInfo);
				out << command << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "insertAfter") {
				int matchInfo;
				in >> matchInfo;
				in >> newInfo;
				isSuccessful = liList.insertAfter(matchInfo, newInfo);
				out << command << " " << matchInfo << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "remove") {
				in >> newInfo;
				isSuccessful = liList.remove(newInfo);
				out << command << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "at") {
				in >> newInfo;
				int returnIndex;
				if (newInfo < liList.size() && newInfo >= 0) {
					returnIndex = liList.at(newInfo);
					out << command << " " << newInfo << " " << returnIndex << endl;
				}
				else {
					out << command << " " << newInfo << endl;
				}
			}
			if (command == "size") {
				int returnSize;
				returnSize = liList.size();
				out << command << " " << returnSize << endl;
			}
			if (command == "clear") {
				isSuccessful = liList.clear();
				out << command << " " << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "printList") {
				string toPrint;
				toPrint = liList.print();
				out << command << " " << toPrint << endl;
			}
		}
		else if (type == "STRING") {
			bool isSuccessful;
			string newInfo;
			if (command == "insertHead") {
				in >> newInfo;
				isSuccessful = lsList.insertHead(newInfo);
				out << command << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "insertTail") {
				in >> newInfo;
				isSuccessful = lsList.insertTail(newInfo);
				out << command << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "insertAfter") {
				string matchInfo;
				in >> matchInfo;
				in >> newInfo;
				isSuccessful = lsList.insertAfter(matchInfo, newInfo);
				out << command << " " << matchInfo << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "remove") {
				in >> newInfo;
				isSuccessful = lsList.remove(newInfo);
				out << command << " " << newInfo << " ";
				out << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "at") {
				int userIndex;
				in >> userIndex;
				string returnIndex;
				if (userIndex < lsList.size() && userIndex >= 0) {
					returnIndex = lsList.at(userIndex);
					out << command << " " << userIndex << " " << returnIndex << endl;
				}
				else {
					out << command << " " << userIndex << endl;
				}
			}
			if (command == "size") {
				int returnSize;
				returnSize = lsList.size();
				out << command << " " << returnSize << endl;
			}
			if (command == "clear") {
				isSuccessful = lsList.clear();
				out << command << " " << (isSuccessful ? "true" : "false") << endl;
			}
			if (command == "printList") {
				string toPrint;
				toPrint = lsList.print();
				out << command << " " << toPrint << endl;
			}
		}
		else {
			out << "Invalid type." << endl;
		}
	}

	in.close();
	out.close();
	
	return 0;
}