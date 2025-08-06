#include <iostream>
#include "fraction.h"
int main()
{
	Fraction n1(1,2);
	Fraction n2(3,5);

	std::cout<<"add"<<std::endl;
	(n1+n2).print();

	std::cout<<"subtraction"<<std::endl;
	(n1-n2).print();

	std::cout<<"mult"<<std::endl;
	(n1*n2).print();

	std::cout<<"division"<<std::endl;
	(n1/n2).print();
	
	std::cout<<"n1<n2 : "<<(n1<n2)<<std::endl;
	std::cout<<"n1>n2 : "<<(n1>n2)<<std::endl;
	std::cout<<"n1==n2 : "<<(n1==n2)<<std::endl;
	std::cout<<"n1!=n2 : "<<(n1!=n2)<<std::endl;

	return 0;
}	
