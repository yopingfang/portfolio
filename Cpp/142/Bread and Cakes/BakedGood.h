/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
*/
#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

class BakedGood {
public:
	BakedGood();
	virtual string ToString() = 0;
	virtual void DiscountedPrice() = 0;
	void SetQuantity(int userIn);
	int GetQuantity() const;
	double GetDiscountPrice() const;
protected:
	double price;
	double discountPrice;
	int quantity;
};

#endif