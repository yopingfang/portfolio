#include<iostream>
#include<string>
#include<fstream>
#include"Set.h"
#include"Map.h"
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

	Map<string, string> pokemon;

	string name;
	string info;
	in >> name; //get rid of "Pokemon:"
	in >> name;
	while (name != "Moves:") {
		in >> info;
		pokemon[name] = info;
		in >> name;
	}
	out << "Pokemon: " << endl;
	out << pokemon.toString();
	out << endl;

	Map<string, string> moves;

	in >> name;
	while (name != "Effectivities:") {
		in >> info;
		moves[name] = info;
		in >> name;
	}
	out << "Moves: " << endl;
	out << moves.toString();
	out << endl;

	Map<string, Set<string>> effectivities;
	in >> name;
	name = name.substr(0, name.size() - 1);
	while (name != "Ineffectivities") {
		getline(in, info);
		istringstream inSS(info);
		string effects;
		while (!inSS.eof()) {
			inSS >> effects;
			effectivities[name].insert(effects);
		}
		in >> name;
		name = name.substr(0, name.size() - 1);
	}
	out << "Effectivities: " << endl;
	out << effectivities.toString();
	out << endl;

	Map<string, Set<string>> ineffectivities;
	in >> name;
	name = name.substr(0, name.size() - 1);
	while (name != "Battles") {
		getline(in, info);
		istringstream inSS(info);
		string ineffects;
		while (!inSS.eof()) {
			inSS >> ineffects;
			ineffectivities[name].insert(ineffects);
		}
		in >> name;
		name = name.substr(0, name.size() - 1);
	}
	out << "Ineffectivities: " << endl;
	out << ineffectivities.toString();
	out << endl;

	out << "Battles:" << endl;
	string fighter1;
	in >> fighter1;
	while (fighter1 != "") {
		fighter1 = fighter1.substr(0, fighter1.size() - 1);
		string move1;
		in >> move1;
		string fighter2;
		in >> fighter2;
		fighter2 = fighter2.substr(0, fighter2.size() - 1);
		string move2;
		in >> move2;

		int f_1_effect = effectivities[moves[move1]].count(pokemon[fighter2]);
		int f_2_effect = effectivities[moves[move2]].count(pokemon[fighter1]);

		out << fighter1 << " (" << move1 << ") vs " << fighter2 << " (" << move2 << "): ";
		if (f_1_effect > f_2_effect) {
			out << fighter1 << " wins!" << endl;
		}
		else if (f_1_effect < f_2_effect) {
			out << fighter2 << " wins!" << endl;
		}
		else {
			f_1_effect = ineffectivities[moves[move1]].count(pokemon[fighter2]);
			f_2_effect = ineffectivities[moves[move2]].count(pokemon[fighter1]);

			if (f_1_effect < f_2_effect) {
				out << fighter1 << " wins!" << endl;
			}
			else if (f_1_effect > f_2_effect) {
				out << fighter2 << " wins!" << endl;
			}
			else {
				out << "Tie!" << endl;
			}
		}
		fighter1 = "";
		in >> fighter1;
	}
	
	in.close();
	out.close();
	return 0;
}