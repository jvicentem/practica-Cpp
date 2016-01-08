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
#include <string>
#include <sstream>

using namespace std;

ItemProcessor::ItemProcessor() :
		_items(0), _numItems(0) {
}

Item* ItemProcessor::get_items() const {
	return _items;
}

void ItemProcessor::set_numItems(unsigned int numItems) {
	_numItems = numItems;
}

ItemProcessor::~ItemProcessor() {
	delete[] get_items();

	delete this;
}

void ItemProcessor::add_item(unsigned int index, const Item& item) {
	_items[index] = item;
}

void ItemProcessor::load(string fileName) {
	IOUtils* io = new IOUtils(fileName);
	string* lines = io->readFile();

	stringstream ss(lines[0]);
	unsigned int numItems_aux;
	ss >> numItems_aux;
	set_numItems(numItems_aux);

	for (unsigned int index = 0; index < numItems_aux; index++) {
		istringstream iss(lines[index]);

		string* words;
		string word = "";

		unsigned int i = 0;
		while (iss >> word) {
			words[i] = word;
			i++;
		}

		Item* item;

		stringstream ss(words[0]);
		unsigned int item_type_aux;
		ss >> item_type_aux;

		switch (item_type_aux) {
			case 1:
			{
				stringstream ss(words[3]);
				float price_aux;
				ss >> price_aux;

				item = new Book(words[1], price_aux, words[2]);
				break;
			}
			case 2:
			{
				stringstream ss(words[3]);
				float price_aux;
				ss >> price_aux;

				stringstream ss2(words[2]);
				unsigned int amount_aux;
				ss2 >> amount_aux;

				item = new Grocery(words[1], price_aux, amount_aux);
				break;
			}
			case 3:
			{
				stringstream ss(words[4]);
				float price_aux;
				ss >> price_aux;

				stringstream ss2(words[3]);
				unsigned int amount_aux;
				ss2 >> amount_aux;

				item = new Toy(words[2], price_aux, amount_aux, words[1]);
				break;
			}
		}

		add_item(index, *item);
	}

	delete [] lines;
}

string ItemProcessor::generateTicket() const {
	string ticket = "";
	Item* itemsArray = get_items();
	float aux_price = 0.0;

	int top = sizeof(itemsArray) / sizeof(itemsArray[0]);

	for (int i = 0; i < top; i++) {
		ticket = ticket + itemsArray[i].generateTicketLine();
		aux_price = aux_price + itemsArray[i].pvp();
	}

	delete[] itemsArray;

	stringstream ss;
	ss << ticket << aux_price << endl;
	return ss.str();
}

float ItemProcessor::pvp() const {
	int pvp = 0.0;

	Item* itemsArray = get_items();

	int top = sizeof(itemsArray) / sizeof(itemsArray[0]);

	for (int i = 0; i < top; i++) {
		pvp = pvp + itemsArray[i].pvp();
	}

	delete[] itemsArray;

	return pvp;
}
