/*
 * IOUtils.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include <string>
#include "IOUtils.h"

using namespace std;

IOUtils::IOUtils(string path) : _path(path) {}

IOUtils::~IOUtils() {}

string IOUtils::get_path() const {
	return _path;
}

/*string* IOUtils::readFile() const {
	return (0);
}*/
