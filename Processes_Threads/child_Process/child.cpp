// first compile this file using -> g++ % -o child 
#include <iostream>	
int main()
{	
	int num;
	std::cout<< "Enter a number"<<std::endl;
	std::cin>> num ;
	for(int i = num-1 ; i > 0 ; i--)
		num *= i; 
	return num ;
}	
