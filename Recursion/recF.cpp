#include <iostream>	

int recF(unsigned int n)
{
	if(n==0) return n;
	if(n==1) return 5;
	if(n==2) return 3;
	if(n==3) return 4;
	if(n==4) return 4;
	return recF(n-5)* recF(n-4) + recF(n-2);
}
int print(int n, int i=0)
{	
	if(i>n) return i;
	std::cout<<recF(i)<<' ';
	return print(n, i+1);
}
int main()
{
	unsigned int n;
	std::cout<<"Enter a number"<<std::endl;
	std::cin>>n;
	std::cout<<recF(n)<<std::endl;
	std::cout<<"array"<<std::endl;
	print(n);
	return 0;
}
