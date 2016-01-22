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

Toy::Toy(string name, double price, unsigned int amount, string brand) : Item(name,price,amount), _brand(brand) {}

Toy::~Toy() {}

string Toy::generateTicketLine() const {
	stringstream ss;
	ss << get_amount() << " " << get_name() << " " << pvpPerUnit() << endl;
	return ss.str();
}

double Toy::pvp() const {
	double price = get_price()+get_price()*TOY_TAX;
	return roundf(price*get_amount()*100) / 100;
}

string Toy::get_brand() const {
	return _brand;
}
