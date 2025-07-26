#include <iostream>	

int printN(int num)
{
	if(num<1) return num;
	printN(num-1);
	std::cout<< num <<' ';
	return num;
}

int main()
{
	int n;
	std::cout<<"Enter a number" << std::endl;
	std::cin>>n;
	printN(n);
	return 0;
}	
