#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int result, num;
	pid_t pid = fork();

	if(pid == 0)
	{
		char* args[] = {(char*)"child", NULL};
		execv(args[0], args);
		std::cout << "Error : child process failed " << std::endl;
		return 1;
	}
	else if(pid > 0) 
	{	
		int status;
		wait(&status);
		if(WIFEXITED(status))
		{
			result = WEXITSTATUS(status);
			std::cout <<"factorial : "<< result <<std::endl;
		}
	}
	else
	{
		std::cout << "Error : Fork failed " << std::endl;
		return 1;
	}
	return 0;
}	
