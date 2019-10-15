#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "myArray.h"
using namespace std;
#define BONUS 0

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

/*********************************************************************
*********************************************************************/
int main(int argc, char * argv[])
{
	VS_MEM_CHECK;

	MyArray<int> numbers(MAX_ARRAY_SIZE);
	std::ostream& out = std::cout;

	out << numbers << endl << endl;

	out << "SEQUENTIAL" << endl;
	MyArray<int>::Iterator iter1 = numbers.begin();
	out << "iter1: " << iter1 << endl;
	for (; iter1 != numbers.end(); ++iter1)
		out << *iter1 << " ";
	out << endl << endl;

#if (BONUS)
	out << "PRIME (Bonus)" << endl;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (isPrime(numbers[i])) out << numbers[i] << " ";
	}
	out << endl << endl;

	out << "COMPOSITE (Bonus)" << endl;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (!isPrime(numbers[i])) out << numbers[i] << " ";
	}
	out << endl << endl;

	out << "FIBONACCI (Bonus)" << endl;
	MyArray<int>::Iterator iter2 = numbers.begin();
	out << "iter2: " << iter2 << endl;
	int n1 = *iter2++;
	int n2 = *iter2++;
	while (iter2 != numbers.end())
	{
		if ((n1 + n2) == *iter2)
		{
			out << *iter2 << "=" << n1 << "+" << n2 << " ";
		}
		n1 = n2;
		n2 = *iter2++;
	}
	out << endl << endl;
#endif
	return 0;
}