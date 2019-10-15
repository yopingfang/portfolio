//  main.cpp

#include <iostream>
#include "ExpressionManager.h"
#include <fstream>
#include <sstream>

//Memory Check stuff
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

using namespace std;


int main(int argc, const char * argv[])
{
	VS_MEM_CHECK // enable memory leak check
				 // Your program...

				 //Setup the input/output
				 //Open the right files
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

		//Run through the lines
		string current_line;
		while (std::getline(in, current_line))
		{
			//Get the raw expression, without "Expression: "
			std::string tempExpression = current_line.substr(current_line.find(" ") + 1);
			//cout << tempExpression << endl;

			//Create the ExpressionManager object
			ExpressionManager e = ExpressionManager(tempExpression);

			//--Output--
			//Original input expression
			//cout << current_line << endl;
			out << current_line << endl;

			try
			{
				//The infix expression (Same as original)
				//cout << "Infix: " << e.infix() << endl;
				out << "     Infix: " << e.infix() << endl;

				//Postfix expression 
				//cout << "Postfix: " << e.postfix() << endl;
				out << "   Postfix: " << e.postfix() << endl;

				//Prefix expression (Bonus)
				//cout << "Prefix: " << "Bonus, not implemented" << endl;
				//out << "    Prefix: " << "Bonus, not implemented" << endl;

				//Value of the expression (and line break)
				//cout << "Value: " << e.value() << endl << endl;
				out << "     Value: " << e.value() << endl << endl;
			}
			catch (const std::invalid_argument& error)
			{
				//If error is caught, output error message
				//cout << "Infix: Caught exception: " << error.what() << endl << endl;
				out << "     Infix: Caught exception: " << error.what() << endl << endl;
				continue;
			}
		}//End While Loop
	//}//End initial IF Statement

//------------Comment out the system("pause"); before turning in
//system("pause");
return 0;
}; //End Main