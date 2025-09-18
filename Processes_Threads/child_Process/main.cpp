#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
int main()
{
	int num;
  	std::cout<< "Enter a number"<<std::endl;
  	std::cin>> num ;
	
	int rw[2];
	pipe(rw);
	pid_t pid = fork();

	if( pid == 0)
	{
		dup2(rw[1], STDOUT_FILENO); 
		close(rw[0]);
		close(rw[1]);

		std::string arg =std::to_string(num);
		char* args[] = {(char*)"./child", (char*)arg.c_str(), NULL};

		execv(args[0], args);
		std::cout << "Error : child failed" << std::endl;
		return 1;
	}
	else if(pid > 0 )
	{
		close(rw[1]);

		char result[100];
		unsigned long long n = read(rw[0], result, sizeof(result)-1);
		result[n] = '\0';
		close(rw[0]);

		wait(NULL);
		std::cout << "Factorial is : " << result << std::endl;
	}
	else
	{
		std::cout << "Error : fork failed" << std::endl;
	}
	return 0;
}	
