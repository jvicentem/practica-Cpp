/*
 * Grocery.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <sstream>
#include "Item.h"
#include "Grocery.h"

using namespace std;

Grocery::Grocery(string name, float price, unsigned int amount) : Item(name,price,amount) {}

Grocery::~Grocery() {
	delete this;
}

string Grocery::generateTicketLine() const {
	stringstream ss;
	ss << " " << get_amount() << " " << get_name() << " " << pvp() << endl;
	return ss.str();
}

float Grocery::pvp() const {
	return get_price()*8.0;
}



