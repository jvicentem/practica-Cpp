/*
 * Grocery.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef GROCERY_H_
#define GROCERY_H_
#include <string>
#include "Item.h"

class Grocery: public Item {
	public:
		Grocery(std::string name, double price, unsigned int amount);

		~Grocery();

		std::string generateTicketLine() const;
		double pvp() const;
};

#endif /* GROCERY_H_ */
