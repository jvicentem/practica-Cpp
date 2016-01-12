/*
 * Item.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */
#include "Item.h"

using namespace std;

Item::Item(string name, float price, unsigned int amount) : _name(name), _price(price), _amount(amount) {}

Item::~Item() {
	delete this;
}

string Item::get_name() const {
	return _name;
}

float Item::get_price() const {
	return _price;
}

int Item::get_amount() const {
	return _amount;
}
