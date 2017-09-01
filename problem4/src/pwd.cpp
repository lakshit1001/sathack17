char* find_path(){
char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
       fprintf(stdout, "Current working dir: %s\n", cwd);
   return cwd;
}

int main(int argc, char const *argv[])
{
	char cwd[1024];
	cwd=find_path();
	fprintf(stdout,cwd);
	return 0;
}