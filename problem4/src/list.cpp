#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <iostream>


void printdir (char *dir);
int k_execute(int argc,char **cmd);

int k_execute(int argc,char **cmd){
  //char *args[2]={cmd,NULL};
  //if(cmd==NULL)
  char *cwd;
  // std::cout<<cmd[0];
    if (argc>1){
      cwd=cmd[1];
    }else{    
      cwd=".";
      // if (getcwd(cwd, sizeof(cwd)) != NULL)
          // fprintf(stdout, "Current working dir: %s\n", cwd);   
    }
  printdir(cwd);
  return 0;
}

void printdir (char *dir) {
    struct dirent *entry;
    DIR *dp = opendir (dir);

    if (dp == NULL) {
        fprintf (stderr, "Cannot open dir:%s\n", dir);
        return;
    }

    chdir (dir);
    while ((entry = readdir(dp)) != NULL){
      write(1,entry -> d_name, strlen(entry -> d_name));
      write(1,"\n",1);
        // printf ("%s\n",entry -> d_name);
    }
    closedir (dp);
}

int main(int argc, char *argv[])
{
  /* code */
  // std::cout<<argc<<std::endl;
  k_execute(argc,argv);
  return 0;
}