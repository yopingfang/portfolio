/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#include <iostream>
using namespace std;

#include "BakedGood.h"
#include "Bread.h"

Bread::Bread() {
	const double BREAD_BASE_PRICE = 4.5;

	price = BREAD_BASE_PRICE;
	type = "none";
}
void Bread::DiscountedPrice() {
	int numDiscount = 0;
	const int NUM_FOR_DISCOUNT = 3;

	discountPrice = price * quantity;
	numDiscount = quantity / NUM_FOR_DISCOUNT;
	discountPrice -= numDiscount * price;
	return;
}
string Bread::ToString() {
	string fullString;

	fullString.append(type);
	fullString.append(" bread ");
	fullString.append(BakedGood::ToString());
	return fullString;
}
void Bread::SetType(string userIn) {
	type = userIn;
	return;
}