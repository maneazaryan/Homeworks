// first compile this file using -> g++ % -o child 
#include <iostream>	
#include <string>
int main(int argc, char* argv[])
{	
	unsigned long long num = std::stoull(argv[1]);
	for(unsigned long long i = num-1 ; i > 0 ; i--)
		num *= i; 
	std::cout << num;
	return 0 ;
}	
