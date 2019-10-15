/*
Po Fang, yopingfang@gmail.com
Description: Create a program that takes orders for bread and cake, discounts them, and prints an invoice
Created 12/6/17
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

int main() {
	vector<BakedGood*> order;
	istringstream inSS;
	string newOrder;
	Bread* newBread;
	CupCake* newCup;
	LayerCake* newLayer;
	string orderDescript;
	int orderQuantity = 0;
	const int SET_PRECISION = 2;
	const int SETW_BAKED = 75;
	const int SETW_OTHER = 9;
	int totalQuant = 0;
	double totalPrice = 0.0;

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	while (newOrder != "done") {
		cout << "Sub - order: " << endl;
		getline(cin, newOrder);
		inSS.str(newOrder);
		inSS >> newOrder;
		if (newOrder == "done") {
			break;
		}
		else if (newOrder == "Bread") {
			newBread = new Bread;
			newBread->SetQuantity(1);
			inSS >> orderDescript;
			newBread->SetType(orderDescript);
			inSS >> orderQuantity;
			for (int i = 0; i < orderQuantity; i++) {
				order.push_back(newBread);
			}
		}
		else if (newOrder == "Cupcake") {
			newCup = new CupCake;
			newCup->SetQuantity(1);
			inSS >> orderDescript;
			newCup->SetFlavor(orderDescript);
			inSS >> orderDescript;
			newCup->SetFrosting(orderDescript);
			inSS >> orderDescript;
			newCup->SetColor(orderDescript);
			inSS >> orderQuantity;

			newCup->AddCreamCheese();
			for (int i = 0; i < orderQuantity; i++) {
				order.push_back(newCup);
			}
		}
		else {
			newLayer = new LayerCake;
			newLayer->SetQuantity(1);
			inSS >> orderDescript;
			newLayer->SetFlavor(orderDescript);
			inSS >> orderDescript;
			newLayer->SetFrosting(orderDescript);
			inSS >> orderQuantity;
			newLayer->SetLayers(orderQuantity);
			inSS >> orderQuantity;

			newLayer->AddCreamCheese();
			newLayer->AddLayersPrice();
			for (int i = 0; i < orderQuantity; i++) {
				order.push_back(newLayer);
			}
		}
		inSS.clear();
	}

	cout << endl << "Order Confirmations:" << endl;
	for (int i = 0; i < order.size(); i++) {
		cout << order.at(i)->ToString() << endl;
	}

	cout << endl << "Invoice: " << endl;
	cout << setw(SETW_BAKED) << left << "Baked Good" << setw(SETW_OTHER) << left << "Quantity" 
		<< setw(SETW_OTHER) << left << "Total" << endl;
	for (int i = 0; i < order.size(); i++) {
		for (int j = i + 1; j < order.size(); j++) {
			if (order.at(i)->ToString() == order.at(j)->ToString()) {
				order.at(i)->SetQuantity(order.at(i)->GetQuantity() + 1);
				order.erase(order.begin() + j);
				j--;
			}
		}
		order.at(i)->DiscountedPrice();
		cout << setw(SETW_BAKED) << left << order.at(i)->ToString() << setw(SETW_OTHER) << left << order.at(i)->GetQuantity()
			<< setw(SETW_OTHER) << left << fixed << setprecision(SET_PRECISION) 
			<< order.at(i)->GetDiscountPrice() << endl;
		totalPrice += order.at(i)->GetDiscountPrice();
		totalQuant += order.at(i)->GetQuantity();
	}
	cout << setw(SETW_BAKED) << left << "Totals" << setw(SETW_OTHER) << left << totalQuant << setw(SETW_OTHER) << left
		<< totalPrice << endl;
	cout << "Good Bye" << endl;

	//system("pause");
	return 0;
}