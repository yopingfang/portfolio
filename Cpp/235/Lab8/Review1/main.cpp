/*PancakeKing
 g++ *.cpp -std=c++17 -o testFile
 ./testFile file4.txt Output_file4.txt
 
 shift command y (editing bar)
 command 0 (tool bar left)
 option command 0 (Tool bar right)
 
 cntrl i (reindents code)
 */
#include<iostream>
#include<sstream>
#include <fstream>
#include<vector>
#include <string>
#include "BST.h"

 #ifdef _MSC_VER
 #define _CRTDBG_MAP_ALLOC
 #include <crtdbg.h>
 #define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
 #else
 #define VS_MEM_CHECK
 #endif

using namespace std;

int main(int argc, char* argv[]){
	   VS_MEM_CHECK               // enable memory leak check
	
	
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
	
	
	BST<int> intBST;
	string input;
	
	while(!in.eof()){
		string parsedInput;
		stringstream ss;
		
		getline(in,input);
		cout << "the input is: " << input << endl;
		ss << input;
		ss >> parsedInput;
		out << parsedInput;
		cout << "the input is: " << parsedInput << endl;
		
		
		if(parsedInput == "Add"){
			int value;
			
			ss >> value;
			
			out << " " << value << " ";
			cout << "the value is: " << value << endl;
			intBST.currentNode = intBST.getRoot();
			if(intBST.addNode(value) == true){
				out << "True" << endl;
				cout << "this value: " << value << "is true" << endl;
			}
			else {
				out << "False" << endl;
				cout << "this value: " << value << "is false" << endl;
			}
		}
		else if(parsedInput == "PrintBST"){
			out << intBST.toString() << endl;
		}
		
		else if(parsedInput == "Remove"){
			int value;
			
			ss >> value;
			
			out << " " << value << " ";
			if(intBST.removeNode(value) == true){
				out << "True" << endl;
			}
			else{
				out << "False" << endl;
			}
		}
		
		else if(parsedInput == "Clear"){
			if(intBST.clearTree()== true){
				out << " True" << endl;
			}
			else{
				out << " False" << endl;
			}
		}
		
	}
	
	return 0;
}
