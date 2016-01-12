/*
 * IOUtils.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef IOUTILS_H_
#define IOUTILS_H_
#include <string>

class IOUtils {
	public:
		IOUtils(std::string path);
		virtual ~IOUtils();
		virtual std::string* readFile() const = 0;

	protected:
		// Attributes
		std::string _path;

		// Getters
		std::string get_path() const;
};

#endif /* IOUTILS_H_ */
