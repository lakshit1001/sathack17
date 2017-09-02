#include <unistd.h>
 #include <iostream>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
#include <stdio.h>


char *p;
struct stat st;

void remove_file(char **argv)
{
	if (stat(argv[1], &st) == 0 && S_ISREG(st.st_mode) || S_ISDIR(st.st_mode))
	{
    	if (asprintf(&p, "%s", argv[1]) != -1)
    	{
//    	    system(p);
//    	    free(p);
    		remove(p);

    	}
	}
	else
	{
		std::cout<<"File not found, Enter valid filename";
	}
}

int main(int argc, char *argv[])
{
	remove_file(argv);
	return 0;
}