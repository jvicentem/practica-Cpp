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

		// Getters
		Item* get_items() const;
};

#endif /* ITEMPROCESSOR_H_ */
