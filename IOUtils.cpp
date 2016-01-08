/*
 * IOUtils.cpp
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */
#include <vector>
#include "IOUtils.h"

using namespace std;

IOUtils::IOUtils(string path) : _path(path) {}

IOUtils::~IOUtils() {
	delete this;
}

string IOUtils::get_path() const {
	return _path;
}


