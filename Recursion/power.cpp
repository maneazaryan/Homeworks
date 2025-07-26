#include <iostream>	

unsigned long long power(int base , int count)
{
	if (count<=0) return 1;
	return base * power(base , count -1);
}
int main()
{
	int n, m;
	std::cout<<"Enter two numbers"<<std::endl;
	std::cin>>n>>m;
	if (n<0 || m<0) return 1;	
	std::cout<<power(n,m)<<std::endl;
	return 0;
}	
