/*
 * Toy.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <sstream>
#include <math.h>
#include "Item.h"
#include "Toy.h"

#define TOY_TAX 0.21;

using namespace std;

Toy::Toy(string name, float price, unsigned int amount, string brand) : Item(name,price,amount), _brand(brand) {}

Toy::~Toy() {
	delete this;
}

string Toy::generateTicketLine() const {
	stringstream ss;
	ss << get_amount() << " " << get_name() << " " << pvp() << endl;
	return ss.str();
}

float Toy::pvp() const {
	float price = get_price()+get_price()*TOY_TAX;
	return roundf(price*100) / 100;
}

string Toy::get_brand() const {
	return _brand;
}
