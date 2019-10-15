/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "BakedGood.h"
#include "Cake.h"

class LayerCake : public Cake {
public:
	LayerCake();
	virtual string ToString();
	virtual void DiscountedPrice();
	void SetLayers(int userIn);
	void AddCreamCheese();
	void AddLayersPrice();
private:
	int layers;
};

#endif