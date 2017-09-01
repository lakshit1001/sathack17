#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <sys/wait.h>

#include "include/inbuilds.h"



void loop();
int k_execute(char **cmd);
char *toCstr(std::string str);

int min(int a, int b);

int main(int argc, char const *argv[])
{
	char **c;
	std::cout<<"Welcome to kash\n";
	loop();
	return 0;
}


char *toCstr(std::string str){
	char *c = new char[str.size()+1];
	for(int i=0;i<str.size();i++){
		c[i]=str[i];
	}
	c[str.size()]='\0';
	return c;
}

void loop(){
	while(1){
		std::string cmd;
		std::vector<std::string> inp;
		std::cout<<"$$ ";
		getline(std::cin,cmd);

		//if empty string, continue;
		if(cmd==""){
			continue;
		}

		std::istringstream iss(cmd);
		std::string word;
		while(iss >> word) {
		    inp.push_back(word);
		}


		char **C = new char*[inp.size()+1];
		for(int i=0;i<inp.size();i++){
			// cout<<i<<" "<<inp[i]<<endl;
			C[i]=toCstr(inp[i]);
		}
		C[inp.size()]=NULL;

		//if the command is shell build in, dont fork
		if(kash::isShellBuildIn(inp[0])){
			if(inp[0]=="cd")
				kash::cd(C);
			continue;
		}

		pid_t wpid;
		pid_t pid = fork();
		if(pid==0){
			//clear
			k_execute(C);
			exit(EXIT_SUCCESS);
		}else if(pid>0){
			//parent
			int status=0;
			do {
			  wpid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			// std::cout<<"Command done"<<std::endl;
		}else{
			std::cout<<"Oops something\n";
		}	
	}
}


int k_execute(char **cmd){	
	int i = execvp(cmd[0],cmd);
	return i;
}

int min(int a, int b){
	if(a<b)
		return a;
	return b;		
}