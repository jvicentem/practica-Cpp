/*
 * TextUtils.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include "IOUtils.h"
#include <string>

class TextUtils: public IOUtils {
	public:
		TextUtils(std::string path);

		virtual ~TextUtils();

		std::string* readFile() const;
};


