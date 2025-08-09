#include <iostream>	
class Fraction{
	private:
		int m_numerator;
		int m_denominator;
	public:
		Fraction(int a, int b):m_numerator(a), m_denominator(b){}
		friend std::ostream& operator <<(std::ostream& os, const Fraction& F);
};

std::ostream& operator <<(std::ostream& os, const Fraction& F ){
	os<<F.m_numerator<<'/'<<F.m_denominator;
	return os;
}	
int main()
{
	Fraction num(3,4);
	std::cout<<num<<std::endl;
	return 0;
}	
