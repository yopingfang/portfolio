
/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#include <iostream>
#include <sstream>
using namespace std;

#include "BakedGood.h"
#include "Cake.h"
#include "LayerCake.h"

LayerCake::LayerCake() {
	const double LAYER_BASE_PRICE = 9.0;

	price = LAYER_BASE_PRICE;
	layers = 0;
}
string LayerCake::ToString() {
	ostringstream OS;
	string fullString;

	OS << layers << "-layer " << flavor << " cake with " << frosting << " frosting " << BakedGood::ToString();
	fullString = OS.str();
	return fullString;
}
void LayerCake::DiscountedPrice() {
	const int DISCOUNT_QUANT = 3;
	const double DISCOUNT_PRICE = 2.0;

	discountPrice = price * quantity;
	if (quantity >= DISCOUNT_QUANT) {
		discountPrice -= DISCOUNT_PRICE * quantity;
	}
	return;
}
void LayerCake::SetLayers(int userIn) {
	layers = userIn;
	return;
}
void LayerCake::AddCreamCheese() {
	const double LAYER_W_CREAM_PRICE = 1.0;

	if (frosting == "cream-cheese") {
		price += LAYER_W_CREAM_PRICE * layers;
	}
	return;
}
void LayerCake::AddLayersPrice() {
	const double EXTRA_LAYERS = 3.0;

		price += EXTRA_LAYERS * (layers - 1);
	
	return;
}