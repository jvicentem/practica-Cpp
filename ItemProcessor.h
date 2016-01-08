/*
 * ItemProcessor.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef ITEMPROCESSOR_H_
#define ITEMPROCESSOR_H_

#include <string>
#include "IOUtils.h"
#include "Item.h"

class ItemProcessor {
	public:
		ItemProcessor();

		~ItemProcessor();

		void load(std::string fileName);
		float pvp() const;
		std::string generateTicket() const;

	private:
		// Attributes
		Item* _items;
		unsigned int _numItems;

		// Getters
		Item* get_items() const;
		Item* get_numItems() const;

		// Setters
		void set_numItems(unsigned int numItems);

		void add_item(unsigned int index, const Item& item);
};

#endif /* ITEMPROCESSOR_H_ */
