#include "teacher.h"

void Teacher::m_printPersonalInfo() {
	Person::m_printPersonalInfo();
	std::cout<<"Subject is "<<m_subject<<std::endl;
	std::cout<<"experience is "<<m_experience<<std::endl;
}
void Teacher::lessExperience(const Teacher& other)const{
	if (m_experience<other.m_experience){
		std::cout<<m_name<<"'s experience is less then  " << other.m_name<<"'s "<<std::endl;
	} else	std::cout<<other.m_name<<"'s experience is less then  " << m_name<<"'s "<<std::endl;
}
bool Teacher::operator < (const Teacher& other) const{
	return m_experience< other.m_experience;
}
