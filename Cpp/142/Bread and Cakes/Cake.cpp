/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#include <iostream>
using namespace std;

#include "Cake.h"
#include "BakedGood.h"

Cake::Cake() {
	flavor = "none";
	frosting = "none";
}
void Cake::SetFlavor(string userIn) {
	flavor = userIn;
	return;
}
void Cake::SetFrosting(string userIn) {
	frosting = userIn;
	return;
}
