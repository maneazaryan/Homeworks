#include <iostream>	

class Fraction{
	private:
		int m_numerator;
		int m_denominator;
		int m_simplify(int a, int b)const;
	public:
		//constructurs
		Fraction(): m_numerator(0), m_denominator(1){}
		Fraction(int a , int b){
			if(b==0){
				std::cout<<"Error. Denominator  can't be 0"<<std::endl;
				m_numerator=0;
				m_denominator=1;
				return;
			}
			m_numerator=a;
			m_denominator=b;
		}
		double m_toDouble(int a , int b) const;

		Fraction operator +(const Fraction& other)const;
		Fraction operator -(const Fraction& other)const;
		Fraction operator * (const Fraction& other)const;
		Fraction operator / (const Fraction& other) const;
		
		bool operator <(const Fraction& other)const ;
		bool operator >(const Fraction& other)const ;
		bool operator ==(const Fraction& other)const ;
		bool operator !=(const Fraction& other)const ;

		void print();
};
void Fraction::print(){
	std::cout<< m_numerator<<'/'<<m_denominator<<std::endl;	
}
int Fraction::m_simplify(int a , int b) const{
	int num;
	int gDivisior=1;
	if (a<0) a=-a;
	if (b<a) b=-b;
	if(a>b)num=b;
	else num=a;
	for(int i=1; i<=num; i++){
		if(a%i==0 && b%i==0)gDivisior=i;
	}
	return gDivisior;
}
double Fraction::m_toDouble(int a , int b)const {
	double aA=static_cast<double>(a);
	double bB=static_cast<double>(b);
	return aA/bB;
}
Fraction Fraction::operator +(const Fraction& other)const{
	int numerator=m_numerator*other.m_denominator + other.m_numerator*m_denominator;
	int denominator = m_denominator * other.m_denominator;
	int gd=m_simplify(numerator, denominator);
	numerator/=gd;
	denominator/=gd;
	return Fraction(numerator,denominator);
}
Fraction Fraction::operator -(const Fraction& other)const {
	int numerator=m_numerator*other.m_denominator - other.m_numerator*m_denominator;
	int denominator=m_denominator * other.m_denominator;
	int gd=m_simplify(numerator, denominator);
	numerator/=gd;
	denominator/=gd;
	return Fraction(numerator,denominator);	
}
Fraction Fraction::operator * (const Fraction& other)const{
	int numerator=m_numerator * other.m_numerator;
	int denominator=m_denominator * other.m_denominator; 
	int gd=m_simplify(numerator, denominator);
	numerator/=gd;
	denominator/=gd;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator / (const Fraction& other) const{
	if(other.m_numerator==0) {
		std::cout<<"Error. denominator can't be 0"<< std::endl;
		return Fraction(0,1);
	}
	int numerator=m_numerator * other.m_denominator;
	int denominator=m_denominator * other.m_numerator;
	int gd=m_simplify(numerator, denominator);
	numerator/=gd;
	denominator/=gd;
	return Fraction(numerator, denominator); 
}
bool Fraction::operator <(const Fraction& other)const {
	double first=m_toDouble(m_numerator, m_denominator);
	double second=m_toDouble(other.m_numerator, other.m_denominator);
	return first<second;
}
bool Fraction::operator >(const Fraction& other)const {
	double first=m_toDouble(m_numerator, m_denominator);
	double second=m_toDouble(other.m_numerator, other.m_denominator);
	return first>second;
}
bool Fraction::operator ==(const Fraction& other)const {
	double first=m_toDouble(m_numerator, m_denominator);
	double second=m_toDouble(other.m_numerator, other.m_denominator);
	return first==second;
}
bool Fraction::operator !=(const Fraction& other)const{
	double first=m_toDouble(m_numerator, m_denominator);
	double second=m_toDouble(other.m_numerator, other.m_denominator);
	return first!=second;
}
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
