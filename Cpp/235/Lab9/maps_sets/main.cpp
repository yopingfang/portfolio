/*
J.Jones, CS235, Section 1
Title: Lab 9 - Pokemon
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using std::endl;
using std::string;
#include "Set.h"
#include "Map.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char** argv)
{
	VS_MEM_CHECK
		if (argc < 3)
		{
			std::cerr << "Please provide name of input and output files";
			return 1;
		}
	std::cout << "Input file: " << argv[1] << endl;
	std::ifstream in(argv[1]);
	if (!in)
	{
		std::cerr << "Unable to open " << argv[1] << " for input";
		system("pause");
		return 2;
	}
	std::cout << "Output file: " << argv[2] << endl;
	std::ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		std::cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	string command;
	in >> command;

	//MAPS:
	Map<string, string> pokemon;
	Map<string, string> movesMap;
	Map<string, Set<string>> effMap;
	Map<string, Set<string>> ineffMap;
	//Sets:
	Set<string> pokedex;

	//POKEMON:
	if (command == "Pokemon:")
	{
		out << command << endl;
		string name;
		string type;
		while (name != "Moves:")
		{
			in >> name;
			if (name == "Moves:") { break; }
			name = name + ":";
			in >> type;
			pokemon[name] = type;
			//For Bonus:
			pokedex.insert(name);
		}
		command = name; //sets command to Moves:
		out << pokemon.toString() << endl;
	}

	//MOVES
	if (command == "Moves:")
	{
		out << command << endl;
		string move;
		string type;
		while (move != "Effectivities:")
		{
			in >> move;
			if (move == "Effectivities:") { break; }
			move = move + ":";
			in >> type;
			movesMap[move] = type;
		}
		out << movesMap.toString() << endl;
		command = move; //sets command to Effectiveness:
	}

	//EFFECTIVITIES:
	if (command == "Effectivities:")
	{
		out << command << endl;
		
		string type;
		string effectiveness = " ";
		string line;
		while (type != "Ineffectivities:")
		{
			getline(in, line);
			if (line == "") { getline(in, line); }
			std::stringstream effLine(line);
			effLine >> type;
			if (type == "Ineffectivities:") { break; }
			for (int i = 0; i < 10; i++)
			{
				effLine >> effectiveness;
				if (effectiveness == "") { break; }
				effMap[type].insert(effectiveness);
			}
		}
		out << effMap.toString() << endl;
		command = type; //sets command to Ineffectiveness:
	}

	//INEFFECTIVITIES:
	if (command == "Ineffectivities:")
	{
		out << command << endl;
		string type;
		string ineffectiveness;
		string line;
		while (type != "Battles:")
		{
				getline(in, line);
				if (line == "") { getline(in, line); }
				std::stringstream ineffLine(line);
				ineffLine >> type;
				if (type == "Battles:") { break; }
				for (int i = 0; i < 10; i++)
				{
					ineffLine >> ineffectiveness;
					if (ineffectiveness == "") { break; }
					ineffMap[type].insert(ineffectiveness);
				}
		}
		command = type; //sets command to Battles:
		out << ineffMap.toString() << endl;
	}

	//BATTLES:
	if (command == "Battles:")
	{
		out << command << endl;
		string pokemon1;
		string move1;
		string pokemon2;
		string move2;
		string moveType;
		string defendersType;
		
		const int FOUND = 1;
		const int EFFECTIVE = 1;
		const int INEFFECTIVE = -1;
		const int NOT_EFFECTIVE = 0;
		int poke1result;
		int poke2result;

		while (!in.eof())
		{
			pokemon1.clear();
			in >> pokemon1 >> move1 >> pokemon2 >> move2;
			if (pokemon1 == "") { break; }
			//if (move2 == "") { break; }
			//POKEMON ONE'S TURN
			moveType = movesMap[move1 + ":"] + ":";
			defendersType = pokemon[pokemon2];
			if (effMap[moveType].count(defendersType) == FOUND) //if effective
			{
				poke1result = EFFECTIVE;
			}
			else if (ineffMap[moveType].count(defendersType) == FOUND) //if ineffective
			{
				poke1result = INEFFECTIVE;
			}
			else //neither
			{
				poke1result = NOT_EFFECTIVE;
			}

			std::stringstream battleResult;
			//POKEMON TWO'S Turn
			moveType = movesMap[move2 + ":"] + ":";
			defendersType = pokemon[pokemon1];
			if (effMap[moveType].count(defendersType) == FOUND) //if effective
			{
				poke2result = EFFECTIVE;
			}
			else if (ineffMap[moveType].count(defendersType) == FOUND) //if ineffective
			{
				poke2result = INEFFECTIVE;
			}
			else //neither
			{
				poke2result = NOT_EFFECTIVE;
			}
			//OUTPUT RESULTS
			pokemon1.erase(pokemon1.end() - 1, pokemon1.end());// removes ":" from name
			pokemon2.erase(pokemon2.end() - 1, pokemon2.end());// removes ":" from name
			if (poke1result > poke2result)
			{
				battleResult << pokemon1 << " wins!";
			}
			else if (poke2result > poke1result)
			{
				battleResult << pokemon2 << " wins!";
			}
			else
			{
				battleResult << "Tie!";
			}
			out << pokemon1 << " (" << move1 << ") vs " << pokemon2 << " (" << move2 << "): " << battleResult.str() << endl;
		}
		
	}

	//BONUS! POKEDEX MODE
	std::stringstream pokemonInSet(pokedex.toString());
	string pokedexName;
	string type;
	pokemonInSet >> pokedexName;
	out << "Pokedex Mode:" << endl;
	while (pokedexName != "");
	{
	Set<string> weak;
	Set<string> resilient;
	out << pokedexName << endl;
	type = pokemon[pokedexName];
	/*for (int i = 0; i < effMap.size(); i++)
	{
		if (effMap)
	}*/
	out << "   Weak against: " << eff[pokedexName].toString() << endl;
	out << "   Resilient to: ";
	}

	return 0;
}