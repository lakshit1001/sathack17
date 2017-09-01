#include "iostream"
#include "vector"
#include "string"
#include <sstream>

using namespace std;



int main(int argc, char const *argv[])
{
	string s = "This is non   sense";
	// string s = "split on    whitespace   ";
	// vector<string> result;
	istringstream iss(s);
	for(string s; iss >> s; )
   	 	cout<<s<<endl;
	return 0;
}