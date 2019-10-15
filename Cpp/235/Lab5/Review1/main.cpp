/*
*Alias: Screenslaver
*CS 235 - Lab 5 Expressions
*/
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <exception>
#include "ExpressionManagerInterface.h"
#include "ExpressionManager.h"
using namespace std;

int main(int argc, char * argv[])
{
	VS_MEM_CHECK;

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

	std::istringstream iss;
	std::string inputExpression;

	while (getline(in, inputExpression)) {
		ExpressionManager expression(inputExpression);

		out << inputExpression << std::endl;

		out << std::setw(12) << "Infix: ";
		try {
			out << expression.infix() << std::endl;
		}
		catch (string e) {
			out << "Caught exception: NOT Infix: " << e << std::endl << std::endl;
			continue;
		}

		out << std::setw(12) << "Postfix: " << expression.postfix() << std::endl;
		
		out << std::setw(12) << "Value: " << expression.value() << std::endl << std::endl;
	}


		return 0;
}