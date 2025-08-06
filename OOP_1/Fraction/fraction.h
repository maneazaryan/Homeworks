#pragma once
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
