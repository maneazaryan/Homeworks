#include "student.h"

bool Student::operator >(const Student& other)const{
	return m_GPA> other.m_GPA;
}
void Student::m_printPersonalInfo(){
	Person::m_printPersonalInfo();
	std::cout<<"University is "<<m_university<<std::endl;
	std::cout<<"Course is "<<m_course<<std::endl;
	std::cout<<"GPA is "<<m_GPA<<std::endl;
}
void Student::higherGPA(const Student& other)const{
	if (m_GPA>other.m_GPA){
		std::cout<<m_name<<"'s GPA is higher then  " << other.m_name<<"'s "<<std::endl;
	} else	std::cout<<other.m_name<<"'s GPA is higher then  " << m_name<<"'s "<<std::endl;
}
