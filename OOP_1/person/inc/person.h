#pragma once
#include <iostream>
#include <string>
class Person{
	public:
		std::string m_name;
		int m_age;
		std::string m_education;
		
		Person():m_name("anonymous"), m_age(0),m_education("low"){}
		Person(std::string name, int age, std::string education )
		: m_name(name), m_age(age), m_education(education){}

		Person(const Person& other){
			m_name=other.m_name;
			m_age=other.m_age;
			m_education=other.m_education;
		}
		virtual ~Person(){}

		virtual void m_printPersonalInfo();
		Person& operator = (const Person& other);
};
