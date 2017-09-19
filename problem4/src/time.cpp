#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
	time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
    printf("%s\n", s);
	return 0;
}