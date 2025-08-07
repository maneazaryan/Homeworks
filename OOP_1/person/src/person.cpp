#include "person.h"

void Person::m_printPersonalInfo(){
	std::cout<<"PERSONAL INFORMATION of "<<m_name<<std::endl;
	std::cout<<"age is "<<m_age<<std::endl;
	std::cout<<"education is "<<m_education<<std::endl;
}
Person& Person::operator = (const Person& other){
	if(this==&other) return *this;
	else{
		m_name=other.m_name;
		m_age=other.m_age;
		m_education=other.m_education;
	}
	return *this;
}
