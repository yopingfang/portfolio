#include<iostream>
#include<fstream>
#include<stdlib.h>
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

	ifstream in(argv[1]);
	if (!in) {
		cout << "Failed to open input file.";
	}
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cout << "Failed to open output file.";
	}



	in.close();
	out.close();
	return 0;
}