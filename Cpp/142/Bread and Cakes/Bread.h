/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"

class Bread : public BakedGood {
public:
	Bread();
	virtual string ToString();
	virtual void DiscountedPrice();
	void SetType(string userIn);
private:
	string type;
};

#endif