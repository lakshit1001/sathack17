#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

char *p;
struct stat st;

int main(int argc, char *argv[])
{
    stat(argv[1], &st);
    std::cout<<st.st_dev<<"ID of device containing file \n";    
std::cout<<st.st_ino<<"inode number \n";    
std::cout<<st.st_mode<<"protection \n";   
std::cout<<st.st_nlink<<"number of hard links \n";  
std::cout<<st.st_uid<<"user ID of owner \n";    
std::cout<<st.st_gid<<"group ID of owner \n";    
std::cout<<st.st_rdev<<"device ID \n";   
std::cout<<st.st_size<<"total size, in bytes \n";   
std::cout<<st.st_blksize<<"blocksize for file system I/O \n";
std::cout<<st.st_blocks<<"number of 512B blocks allocate \n"; 
std::cout<<st.st_atime<<"time of last access \n";  
std::cout<<st.st_mtime<<"time of last modification \n";  
std::cout<<st.st_ctime<<"tim of last status change \n";  
  
    
}
