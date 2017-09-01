#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <sys/wait.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

using namespace std;

void loop();
int k_execute(char **cmd);
int min(int a, int b);

int main(int argc, char const *argv[])
{
	cout<<"Welcome to kash\n";
	loop();
	return 0;
}


char *toCstr(string str){
	char *c = new char[str.size()+1];
	for(int i=0;i<str.size();i++){
		c[i]=str[i];
	}
	c[str.size()]='\0';
	return c;
}

void loop(){
	while(1){
		string cmd;
		vector<string> inp;
		cout<<"$$ ";
		getline(cin,cmd);
		istringstream iss(cmd);
		string word;
		while(iss >> word) {
		    inp.push_back(word);
		}

		char **C = new char*[inp.size()+1];
		for(int i=0;i<inp.size();i++){
			// cout<<i<<" "<<inp[i]<<endl;
			C[i]=toCstr(inp[i]);
		}
		C[inp.size()]=NULL;

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
			cout<<"Command done"<<endl;
		}else{
			cout<<"Oops something\n";
		}	
	}
}


int k_execute(char **cmd){
    // char *args[2]={cmd,NULL};	
	int i = execvp(cmd[0],cmd);
	// cout<<cmd<<"Hello"<<i;
	return i;
}

int min(int a, int b){
	if(a<b)
		return a;
	return b;		
}