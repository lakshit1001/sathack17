#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[]){
	int a,b;
	if(argc==1){
		cin>>a>>b;
		cout<<a+b<<endl;
		return 0;
	}
	if(argc!=3){
		cerr<<"Incorrect number of args arguments "<<argc;
		return -1;
	}

	cout<<atoi(argv[1])+atoi(argv[2])<<endl;
	return 0;
}