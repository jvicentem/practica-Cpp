/*
 * IOUtils.h
 *
 *  Created on: 2 Jan 2016
 *      Author: jose
 */

#ifndef IOUTILS_H_
#define IOUTILS_H_

class IOUtils {
	public:
		IOUtils(std::string path);

		virtual ~IOUtils();

		virtual std::vector<std::vector<std::string>> readFile() const;

	protected:
		// Attributes
		std::string _path;

		// Getters
		std::string get_path() const;
};

#endif /* IOUTILS_H_ */
