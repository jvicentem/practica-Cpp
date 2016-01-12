/*
 * Toy.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef TOY_H_
#define TOY_H_
#include <string>
#include "Item.h"

class Toy: public Item {
	public:
		Toy(std::string name, float price, unsigned int amount, std::string brand);

		~Toy();

		std::string generateTicketLine() const;
		float pvp() const;

	private:
		// Attribute
		std::string _brand;

		// Getters
		std::string get_brand() const;
};

#endif /* TOY_H_ */
