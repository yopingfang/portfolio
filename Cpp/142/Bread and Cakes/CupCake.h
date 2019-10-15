/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"
#include "BakedGood.h"

class CupCake : public Cake {
public:
	CupCake();
	virtual string ToString();
	virtual void DiscountedPrice();
	void SetColor(string userIn);
	void AddCreamCheese();
private:
	string sprinkleColor;
};

#endif