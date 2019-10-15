/*Bob Smith
Lab 1 - RPG
*/

//Checks for memory leaks
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include "Arena.h"
#include "ArenaInterface.h"
#include "FighterInterface.h"
#include <fstream>
#include "Fighter.h"
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
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
	
	string line;
	string fighterTitle = "";
	char fighterType = 'X';
	int maxHits = 0;
	int strength = 0;
	int speed = 0;
	int magic = 0;
	bool useAbility = false;

	string userChoice = "";
	
	Arena newArena;

	cout << "Enter Option:" << endl;
	getline(in, userChoice);
	
	if (userChoice == "USE ABILITY")
	{
		useAbility = true;
	}


	while (!in.eof())
	{
		in >> userChoice;
		if (userChoice == "getSize")
		{
			out << "getSize ";
			out << newArena.getSize() << endl;
		}
		else if (userChoice == "getFighter")
		{
			string name = "uninit";
			in >> name;
			
			out << "getFighter " << name;
			if (newArena.getFighter(name) != nullptr)
			{
				out << endl;
				out << "  " << newArena.getFighter(name)->toString();
				out << endl;
			}
			else
			{
				out << " NULL" << endl;
			}
		}
		else if (userChoice == "addFighter" )
		{
			string info = "uninit";
			out << "addFighter ";
			getline(in, info);
			out << info << " ";
			bool newFighter = newArena.addFighter(info);
			if (newFighter == true)
			{
				out << "Added";
			}
			else
			{
				out << "Invalid";
			}
			out << endl;
				 
		}
		else if (userChoice == "removeFighter")
		{
			out << "removeFighter ";
			in >> userChoice;
			out << userChoice << " ";
			if (newArena.removeFighter(userChoice) == true)
			{
				out << "True" << endl;
			}
			else
			{
				out << "False" << endl;
			}
		}
		else if (userChoice == "battle")
		{
			string fighterA;
			string fighterB;
			in >> fighterA;
			in >> fighterB;
			out << "battle " << fighterA << " " << fighterB << endl << endl;
			FighterInterface* fighterPtr1 = newArena.getFighter(fighterA);
			FighterInterface* fighterPtr2 = newArena.getFighter(fighterB);
			in.ignore(1000, '\n');
			bool battle = true;

			if (fighterPtr1 == nullptr || fighterPtr2 == nullptr)
			{
				out << "Battle not possible because one or both fighters do not exist" << endl;
			}
			else
			{
				while (battle)
				{
					out << " " << fighterPtr1->toString();
					out << endl;
					out << " " << fighterPtr2->toString();
					out << endl << endl;

					if (useAbility)
					{
						fighterPtr1->regenerate();
						fighterPtr1->useAbility();

					}
					int damage;
					damage = fighterPtr1->getDamage();
					fighterPtr2->takeDamage(damage);

					if (fighterPtr2->getCurrentHP() <= 0)
					{
						out << " " << fighterPtr1->toString() << endl;
						out << " " << fighterPtr2->toString() << endl;
						battle = false;
					}
					else
					{
						if(useAbility)
						{
							fighterPtr2->regenerate();
							fighterPtr2->useAbility();
						}
						int damage = 0;
						damage = fighterPtr2->getDamage();
						fighterPtr1->takeDamage(damage);
						if (fighterPtr1->getCurrentHP() <= 0)
						{
							out << " " << fighterPtr1->toString() << endl;
							out << " " << fighterPtr2->toString() << endl;
							battle = false;
						}

					}
				}
			}

		}
		else if (userChoice == "reset")
		{
			string name = "";
			in >> name;
			if (newArena.getFighter(name) != nullptr)
			{
				FighterInterface* newFighter = newArena.getFighter(name);
				newFighter->reset();
				out << "reset " << name << " Success" << endl;
			}
			else
			{
				out << "reset" << name << " "  << endl;
			}

		}
		else 
		{
			out << "Invalid entry. Try again" << endl;
			
		}

	}

	newArena.quit();
	

	return 0;
}