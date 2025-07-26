#include <iostream>	

int factorial(int num)
{
	if(num <= 1) return 1;
	return num*factorial(num-1);
}
int main()
{
	int n;
	std::cout<<"Enter a number"<<std::endl;
	std::cin>>n;
	if(n<0) 
	{
		std::cout<<"Error"<<std::endl;
		return 1;
	}
	std::cout<<factorial(n)<<std::endl;
	return 0;
}	
