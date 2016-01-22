/*
 * Book.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <string>
#include "Item.h"

class Book: public Item {
	public:
		Book(std::string name, double price, std::string author);

		~Book();

		std::string generateTicketLine() const;
		double pvp() const;

	private:
		// Attribute
		std::string _author;

		// Getters
		std::string get_author() const;
};

#endif /* BOOK_H_ */
