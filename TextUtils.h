/*
 * TextUtils.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#include "IOUtils.h"

class TextUtils: public IOUtils {
	public:
		TextUtils(std::string path);

		~TextUtils();

		std::vector<std::vector<std::string>> readFile() const;
};


