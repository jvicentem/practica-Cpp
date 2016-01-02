/*
 * ItemProcessor.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include "ItemProcessor.h"
#include "Item.h"
#include "Book.h"
#include "Grocery.h"
#include "Toy.h"
#include "IOUtils.h"

using namespace std;

	ItemProcessor::ItemProcessor() : _items(0) {}

	Item* ItemProcessor::get_items() const {
		return _items;
	}

	ItemProcessor::~ItemProcessor() {
		delete [] get_items();

		delete this;
	}

	void ItemProcessor::load(string fileName) {
		IOUtils* io = new IOUtils(fileName);
		vector<vector<string>> lines = io->readFile();

		unsigned int index = 0;

		for (iterator itLines = lines.begin() ; itLines != lines.end(); ++itLines) {
			for (iterator it = itLines ; it != lines.end(); ++it) {
				  Item* i;

				  string e = *it;

			      switch (isdigit((e[0]))) {
			         case '1':
			        	 stringstream ss(e[3]);
			        	 float price_aux;
			        	 ss >> price_aux;

			        	 i = new Book(e[1],price_aux,e[2]);
			            break;
			         case '2':
						stringstream ss(e[3]);
						float price_aux;
						ss >> price_aux;

						int amount_aux;
						ss(e[2]) >> amount_aux;

						i = new Grocery(e[1],price_aux,amount_aux);
			            break;
			         case '3':
						stringstream ss(e[4]);
						float price_aux;
						ss >> price_aux;

						int amount_aux;
						ss(e[3]) >> amount_aux;

			        	i = new Toy(e[2],price_aux,amount_aux,e[1]);
			        	break;
			      }

			      get_items()[index] = i;

			      index++;
			}
		}

		lines.clear();
		delete lines;
	}

	string ItemProcessor::generateTicket() const {
		string ticket = "";
		Item* itemsArray = get_items();

		unsigned int top = sizeof(itemsArray) / sizeof(itemsArray[0]);

		for (int i = 0; i<top; i++) {
			ticket = ticket + itemsArray[i].generateTicketLine();
		}

		delete [] itemsArray;

		return ticket;
	}

	float ItemProcessor::pvp() const {
		int pvp = 0.0;

		Item* itemsArray = get_items();

		unsigned int top = sizeof(itemsArray) / sizeof(itemsArray[0]);

		for (int i = 0; i<top; i++) {
			pvp = pvp + itemsArray[i].pvp();
		}

		delete [] itemsArray;

		return pvp;
	}
