#include <iostream>	

int greatestDivisor(int first, int second)
{
	if( first % second == 0) return second ;
	return greatestDivisor( first , second-1);
}
int main()
{
	int n, m;
	std::cout<<"Enter two numbers"<<std::endl;
	std::cin>>n>>m;

	if(n==0 || m==0) 
	{	
		std::cout<<"Error"<<std::endl;
		return 1;
	}
	if(n > m) std::cout<<greatestDivisor(n, m)<<std::endl;
	else std::cout<<greatestDivisor(m,n)<<std::endl;
	return 0;
}	
