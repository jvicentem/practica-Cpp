/*
 * TextUtils.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "TextUtils.h"
#include "IOUtils.h"

using namespace std;

TextUtils::TextUtils (string path) : IOUtils(path) {}

TextUtils::~TextUtils() {}

string* TextUtils::readFile() const {
	ifstream in (get_path().c_str());

	string numItemsAux;
	getline(in, numItemsAux);

	unsigned int numItems = atoi(numItemsAux.c_str());
	unsigned int arraySize = numItems+1;
	string* lines = new string[arraySize];
	lines[0] = numItemsAux;
	string line;
	unsigned int i = 1;
	while (getline(in, line) && i<arraySize) {
		lines[i] = line;
		i++;
	}

	in.close();

	return lines;
}

