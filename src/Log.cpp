#include "Headers/Log.h"
#include <stdlib.h>
#define RED     "\033[31m" 
#define GREEN   "\033[32m" 
#define RESET   "\033[0m"

void Log::messageLog(const std::string&& msg) {

	std::cout << GREEN <<"[Message-Log]: " << msg << RESET << std::endl;
}

void Log::errorLog(const std::string&& msg) {
	
	std::cout << RED << "[Error-Log]: " << msg << RESET << std::endl;
}
