/*
 * Grocery.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <sstream>
#include <math.h>
#include "Item.h"
#include "Grocery.h"

#define GROCERY_TAX 0.08;

using namespace std;

Grocery::Grocery(string name, double price, unsigned int amount) : Item(name,price,amount) {}

Grocery::~Grocery() {}

string Grocery::generateTicketLine() const {
	stringstream ss;
	ss << get_amount() << " " << get_name() << " " << pvpPerUnit() << endl;
	return ss.str();
}

double Grocery::pvp() const {
	double price = get_price()+get_price()*GROCERY_TAX;
	return roundf(price*get_amount()*100) / 100;
}



