#include<iostream>
using namespace std;

int main() {

	int *ptr = nullptr;
	ptr = new int;
	*ptr = 10;
	cout << *ptr << endl << &ptr << endl;

	int **newPtr = &ptr;

	cout << **newPtr << endl << *newPtr << endl << &newPtr;

	system("pause");

	return 0;
}