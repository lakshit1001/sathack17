#include "inbuilds.h"

int kash::cd(char **cmd){
	char *path;
	if(cmd[1]==NULL)
		path="/home";
	else path=cmd[1];
	if(chdir(path)==-1){
		std::cout<<"cd: Invalid Path\n";
	}
}	

bool kash::isShellBuildIn(std::string cmd){
	if(cmd=="cd")
		return true;
}