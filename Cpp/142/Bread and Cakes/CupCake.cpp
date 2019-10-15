/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#include <iostream>
using namespace std;

#include "Cake.h"
#include "BakedGood.h"
#include "CupCake.h"

CupCake::CupCake() {
	const double CUP_BASE_PRICE = 1.95;

	sprinkleColor = "none";
	price = CUP_BASE_PRICE;
}
string CupCake::ToString() {
	string fullString;

	fullString.append(flavor);
	fullString.append(" cupcake with ");
	fullString.append(frosting);
	fullString.append(" frosting and ");
	fullString.append(sprinkleColor);
	fullString.append(" sprinkles ");
	fullString.append(BakedGood::ToString());
	return fullString;
}
void CupCake::DiscountedPrice() {
	const int SMALL_DISCOUNT_REQ = 2;
	const double SMALL_DISCOUNT_AMOUNT = 0.3;
	const int LARGE_DISCOUNT_REQ = 4;
	const double LARGE_DISCOUNT_AMOUNT = 0.4;

	discountPrice = price * quantity;
	if (quantity >= SMALL_DISCOUNT_REQ && quantity < LARGE_DISCOUNT_REQ) {
		discountPrice -= quantity * SMALL_DISCOUNT_AMOUNT;
	}
	if (quantity >= LARGE_DISCOUNT_REQ) {
		discountPrice -= quantity * LARGE_DISCOUNT_AMOUNT;
	}
	return;
}
void CupCake::SetColor(string userIn) {
	sprinkleColor = userIn;
	return;
}
void CupCake::AddCreamCheese() {
	const double CUP_W_CREAM_PRICE = 0.2;

	if (frosting == "cream-cheese") {
		price += CUP_W_CREAM_PRICE;
	}
	return;
}