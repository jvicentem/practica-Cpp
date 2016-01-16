/*
 * Item.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <string>

class Item {
	public:
		Item (std::string name, float price, unsigned int amount);

		virtual ~Item();

		virtual std::string generateTicketLine() const = 0;
		virtual double pvp() const = 0;

	protected:
		// Attributes
		std::string _name;
		double _price;
		unsigned int _amount;

		// Getters
		std::string get_name() const;
		double get_price() const;
		unsigned int get_amount() const;

		double pvpPerUnit() const;
};

#endif /* ITEM_H_ */
