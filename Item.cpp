/*
 * Item.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <math.h>
#include "Item.h"

using namespace std;

Item::Item(string name, float price, unsigned int amount) : _name(name), _price(price), _amount(amount) {}

Item::~Item() {}

string Item::get_name() const {
	return _name;
}

double Item::get_price() const {
	return _price;
}

unsigned int Item::get_amount() const {
	return _amount;
}

double Item::pvpPerUnit () const {
	return roundf((pvp()/get_amount())*100) / 100;
}
