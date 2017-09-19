#ifndef INBUILDS_H
#define INBUILDS_H

#include <iostream>
#include <string>
#include <unistd.h>

namespace kash {
	int cd(char **cmd);	
	bool isShellBuildIn(std::string);	
} // kash		

#endif // INBUILDS_H
