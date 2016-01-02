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

TextUtils::TextUtils (string path) : _path(path) {}

TextUtils::~TextUtils() {
	delete this;
}

vector<vector<string>> TextUtils::readFile() const {
	vector<vector<string>> lines;
	vector<string> buffer;

	unsigned int numItems;
	string line;

	ifstream in (get_path().c_str());
	in >> numItems;

	for (unsigned int i = 0; i < numItems; i++) {
		string word;
		in >> word;
		buffer.push_back(word);

		if (word.find('\n') > 0) {
			lines.push_back(buffer);
			buffer.clear();
		}
	}

	buffer.clear();
	delete buffer;

	return lines;
}

