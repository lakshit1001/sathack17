#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
 
#include <iostream>
#include <string>
 
#include <cstdlib>
 
void touch(const std::string& pathname)
{
    int fd = open(pathname.c_str(),
                  O_WRONLY|O_CREAT|O_NOCTTY|O_NONBLOCK,
                  0666);
    if (fd<0) // Couldn't open that path.
    {
        std::cerr
            << __PRETTY_FUNCTION__
            << ": Couldn't open() path \""
            << pathname
            << "\"\n";
        return;
    }
    int rc = utimensat(AT_FDCWD,
                       pathname.c_str(),
                       NULL,
                       0);
    if (rc)
    {
        std::cerr
            << __PRETTY_FUNCTION__
            << ": Couldn't utimensat() path \""
            << pathname
            << "\"\n";
        return;
    }
    std::clog
        << __PRETTY_FUNCTION__
        << ": Completed touch() on path \""
        << pathname
        << "\"\n";
}
 
int main(int argc, char* argv[])
{
    if (argc!=2)
        return EXIT_FAILURE;
    touch (argv[1]);
    return EXIT_SUCCESS;
}
