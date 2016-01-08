/*
 * Book.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */
#include "Item.h"
#include "Book.h"
#include <sstream>

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
	return get_price()*16.0;
}

string Book::get_author() const {
	return _author;
}



