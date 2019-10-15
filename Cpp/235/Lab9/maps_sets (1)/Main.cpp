/*Srinivasa Ramanujan		8/07/2018		CS 235			HashMap Lab
Battle Pokemon!
*/

/*FYI the code is not finished*/
#include "Map.h"
#include "Set.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;

#endif

int main(int argc, char* argv[])
{
	VS_MEM_CHECK				//Checks that there are no memory leaks

		if (argc < 3)				//Checks input file and output file input
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

	string dataLine;
	string command = "";

	Map<string, string> pokemon;
	Map<string, string> move;

	Map<string, Set<string>> effectivities;
	Map<string, Set<string>> ineffectivities;

	while(getline(in, dataLine))
	{
		stringstream data;

		if (dataLine == "\n")
		{
			command = "";
		}
		else if (dataLine == "Pokemon:" || dataLine == "Moves:" || dataLine == "Effectivities:"
			|| dataLine == "Ineffectivities:" || dataLine == "Battles:")
		{
			command = dataLine;
		}
		else if (command == "Pokemon:")
		{
			data << dataLine;
			string pName, pType;
			data >> pName >> pType;

			pokemon[pName] = pType;

			out << dataLine << endl;
		}
		else if (command == "Moves:")
		{
			data << dataLine;
			string mName, mType;
			data >> mName >> mType;

			move[mName] = mType;

			out << dataLine << endl;
		}
		else if (command == "Effectivities:")
		{
			data << dataLine;
			string mType, eType;
			data >> mType;
			Set<string> effectTypes;
			while (data >> eType)
			{
				effectTypes.insert(eType);
			}

			effectivities[mType] = effectTypes;
		}
		else if (command == "Ineffectivities:")
		{
			data << dataLine;
			string mType, iType;
			data >> mType;
			Set<string> ineffectTypes;
			while (data >> iType)
			{
				ineffectTypes.insert(iType);
			}

			ineffectivities[mType] = ineffectTypes;

		}
		else if (command == "Battles:")
		{
			data << dataLine;
			string fName, fMove, sName, sMove;
			data >> fName >> fMove >> sName >> sMove;

			out << fName << " (" << fMove << ") vs ";
			out << sName << " (" << sMove << "): ";

			string fType = pokemon[fName];
			string sType = pokemon[sName];

			int fEff = effectivities[fMove].count(sType);
			int sEff = effectivities[sMove].count(fType);
			
			if (fEff > sEff)
			{
				out << fName << " wins!";
			}
			else if (sEff > fEff)
			{
				out << sName << " wins!";
			}
			else
			{
				fEff = ineffectivities[fMove].count(sType);
				sEff = ineffectivities[sMove].count(fType);

			}
			
		}

		data.clear();
	}



	in.close();
	out.close();

	return 0;
}