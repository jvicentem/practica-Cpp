/*
 * ItemProcessor.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <string>
#include <sstream>
#include <stdlib.h>
#include "ItemProcessor.h"
#include "Item.h"
#include "Book.h"
#include "Grocery.h"
#include "Toy.h"
#include "IOUtils.h"
#include "TextUtils.h"

using namespace std;

ItemProcessor::ItemProcessor() :
		_items(0), _numItems(0) {
}

Item** ItemProcessor::get_items() const {
	return _items;
}

unsigned int ItemProcessor::get_numItems() const {
	return _numItems;
}

void ItemProcessor::set_numItems(unsigned int numItems) {
	_numItems = numItems;
}

ItemProcessor::~ItemProcessor() {
	for (unsigned int i = 0; i < get_numItems(); i++) {
		delete _items[i];
	}

	delete [] _items;
}

void ItemProcessor::load(string fileName) {
	IOUtils *io = new TextUtils(fileName);

	string* lines = io->readFile();

	delete io;

	unsigned int numItemsAux = atoi(lines[0].c_str());

	set_numItems(numItemsAux);

	_items = new Item*[numItemsAux];

	for (unsigned int index = 0; index < numItemsAux; index++) {
		istringstream iss(lines[(index+1)]);

		string* words = new string[5]; //5 porque una línea tiene como máximo 5 palabaras
		string word = "";
		unsigned int i = 0;

		while (iss >> word) {
			words[i] = word;
			i++;
		}

		Item* item = 0;

		unsigned int itemTypeAux = atoi(words[0].c_str());

		switch (itemTypeAux) {
			case 1:
			{
				float priceAux = atof(words[3].c_str());

				item = new Book(words[1], priceAux, words[2]);

				break;
			}
			case 2:
			{
				float priceAux = atof(words[3].c_str());

				unsigned int amountAux = atoi(words[2].c_str());

				item = new Grocery(words[1], priceAux, amountAux);

				break;
			}
			case 3:
			{
				float priceAux = atof(words[4].c_str());

				unsigned int amount_aux = atoi(words[3].c_str());

				item = new Toy(words[2], priceAux, amount_aux, words[1]);

				break;
			}
		}

		delete [] words;
		_items[index] = item;
	}

	delete [] lines;
}

float ItemProcessor::pvp() const {
	float pvp = 0.0;
	Item** itemsArray = get_items();
	unsigned int top = get_numItems();

	for (unsigned int i = 0; i < top; i++) {
		pvp = pvp + itemsArray[i]->pvp();
	}

	return pvp;
}

string ItemProcessor::generateTicket() const {
	string ticket = "";
	Item** itemsArray = get_items();
	float aux_price = 0.0;

	unsigned int top = get_numItems();

	for (unsigned int i = 0; i < top; i++) {
		ticket = ticket + itemsArray[i]->generateTicketLine();
		aux_price = aux_price + itemsArray[i]->pvp();
	}

	stringstream ss;
	ss << ticket << aux_price << endl;
	return ss.str();
}
