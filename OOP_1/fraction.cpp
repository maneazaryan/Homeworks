#include <iostream>	

class Fraction{
	private:
		double m_numerator;
		double m_denominator;
	public:
		//constructurs
		Fraction(): m_numerator(0), m_denominator(1){}
		Fraction(double a , double b){
			if(b==0){
				std::cout<<"Error"<<std::endl;
				return;
			}
			m_numerator=a;
			m_denominator=b;
		}
		//arithmetic operators  +,  -,  *,  / 
		Fraction operator +(const Fraction& other)const{
			double numerator=m_numerator*other.m_denominator + other.m_numerator*m_denominator;
			double denominator = m_denominator * other.m_denominator;
			return Fraction(numerator,denominator);
		}
		Fraction operator -(const Fraction& other)const {
			double numerator=m_numerator*other.m_denominator - other.m_numerator*m_denominator;
			double denominator=m_denominator * other.m_denominator;
			return Fraction(numerator,denominator);	
		}
		Fraction operator * (const Fraction& other)const{
			double numerator=m_numerator * other.m_numerator;
			double denominator=m_denominator * other.m_denominator; 
			return Fraction(numerator, denominator);
		}
		Fraction operator / (const Fraction& other) const{
			double numerator=m_numerator * other.m_denominator;
			double denominator=m_denominator * other.m_numerator;
			return Fraction(numerator, denominator); 
		}

		//prdouble
		void prdouble();
};
void Fraction::prdouble(){
	std::cout<< m_numerator<<'/'<<m_denominator<<std::endl;	
}

int main()
{
	Fraction n1(1,2);
	Fraction n2(4,6);
	Fraction n3=n1+n2;
	n3.prdouble();

	return 0;
}	
