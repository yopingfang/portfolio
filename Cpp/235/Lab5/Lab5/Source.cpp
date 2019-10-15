//created by pp
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"ExpressionManager.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

int main(int argc, char* argv[]) {

	VS_MEM_CHECK;

	ifstream in(argv[1]);
	ofstream out(argv[2]);

	ExpressionManager *ptr = nullptr;
	while (!in.eof()) {
		string command;
		in >> command;
		if (command == "Expression:") {
			string expression;
			getline(in, expression);
			ptr = new ExpressionManager;
			ptr->setExpression(expression);
			out << command << expression << endl;
			out << "Infix: " << ptr->infix() << endl;
			istringstream inSS(ptr->infix());
			string errorCheck;
			inSS >> errorCheck;
			if (errorCheck != "Caught") {
				out << "Postfix: " << ptr->postfix() << endl;
				out << "Value: " << ptr->value() << endl;
			}
			delete ptr;
		}
		out << endl;
	}
	in.close();
	out.close();
	return 0;
}