#pragma once
#include <iostream>

static class Log {

private:
	

public:

	static void messageLog(const std::string&& msg);
	static void errorLog(const std::string&& msg);
	
};

