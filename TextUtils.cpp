/*
 * TextUtils.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include "TextUtils.h"
#include "IOUtils.h"
#include <fstream>
#include <sstream>

using namespace std;

TextUtils::TextUtils (string path) : IOUtils(path) {}

TextUtils::~TextUtils() {
	delete this;
}

string* TextUtils::readFile() const {
	unsigned int numItems, i;

	ifstream in (get_path().c_str());
	in >> numItems;

	string lines[numItems];
	lines[0] = numItems;

	string line;
	i = 1;
	while (getline(in, line)) {
		lines[i] = line;
		i++;
	}

	return lines;
}

