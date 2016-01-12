/*
 * TextUtils.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef TEXTUTILS_H_
#define TEXTUTILS_H_

#include "IOUtils.h"
#include <string>

class TextUtils: public IOUtils {
	public:
		TextUtils(std::string path);

		virtual ~TextUtils();

		std::string* readFile() const;
};

#endif /* TEXTUTILS_H_ */
