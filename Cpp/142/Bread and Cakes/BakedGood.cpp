/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "BakedGood.h"

BakedGood::BakedGood() {
	quantity = 0;
	price = 0.0;
	discountPrice = 0.0;
}
string BakedGood::ToString() {
	string fullString;
	ostringstream OS;
	const int SET_PRECISION = 2;
	
	OS << "($" << fixed << setprecision(SET_PRECISION) << price << ")";
	fullString = OS.str();
	return fullString;
}
void BakedGood::SetQuantity(int userIn) {
	quantity = userIn;
	return;
}
int BakedGood::GetQuantity() const {
	return quantity;
}
double BakedGood::GetDiscountPrice() const {
	return discountPrice;
}


