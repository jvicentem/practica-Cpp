/*
 * Book.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <sstream>
#include <math.h>
#include "Item.h"
#include "Book.h"

#define BOOK_TAX 0.16;

using namespace std;

Book::Book(string name, float price, string author) : Item(name,price,1), _author(author) {}

Book::~Book() {
	delete this;
}

string Book::generateTicketLine() const {
	stringstream ss;
	ss << get_name() << " " << pvp() << endl;
	return ss.str();
}

float Book::pvp() const {
	float price = get_price()+get_price()*BOOK_TAX;
	return roundf(price*100) / 100;
}

string Book::get_author() const {
	return _author;
}



