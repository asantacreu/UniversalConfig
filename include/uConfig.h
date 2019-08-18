#ifndef UCONFIG_H_
#define UCONFIG_H_

#include <string>
#include <map>

#include "exports.h"

class UCONFIG_API UConfig {
	public:
		void LoadConfigFile(std::string filePath);
		void Save();

		void SetString(std::string key, std::string value);
		std::string GetString(std::string key) const;

	private:
		std::map<std::string, std::string> strings;

};

#endif // UCONFIG_H_

