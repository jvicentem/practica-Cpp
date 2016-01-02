/*
 * Toy.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include "Item.h"
#include "Toy.h"

using namespace std;

Toy::Toy(string name, float price, unsigned int amount, string brand) : Item(name,price,amount), _brand(brand) {}

Toy::~Toy() {
	delete this;
}

string Toy::generateTicketLine() const {
	stringstream ss;
	ss << " " << get_amount() << " " << get_name() << " " << pvp() << endl;
	return ss.str();
}

float Toy::pvp() const {
	return get_price()*21.0;
}

string Toy::get_brand() const {
	return _brand;
}
