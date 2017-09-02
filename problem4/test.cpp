#include "iostream"
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>


using namespace std;



int main(int argc, char const *argv[]){
	int old_out = dup(1);
    close(1); // Release fd no - 1
    open("test2.txt", O_CREAT | O_RDWR , S_IRUSR | S_IWUSR); // Open a file with fd no = 1
    write(1,"hello world1",12);
    dup2(old_out,1);
    write(1,"hello world2",12);
	return 0;
}