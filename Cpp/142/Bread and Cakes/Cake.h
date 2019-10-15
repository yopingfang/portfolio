/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#ifndef CAKE_H
#define CAKE_H

#include "BakedGood.h"

class Cake : public BakedGood {
public:
	Cake();
	virtual string ToString() = 0;
	virtual void DiscountedPrice() = 0;
	void SetFlavor(string userIn);
	void SetFrosting(string userIn);
protected:
	string frosting;
	string flavor;
};

#endif