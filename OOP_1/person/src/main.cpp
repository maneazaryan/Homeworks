#include <iostream>	
#include <string>
#include "person.h"
#include "student.h"
#include "teacher.h"

int main()
{
	Person p_n1("An", 23, "high");
	//p_n1.m_printPersonalInfo();
	Person* p_n2= &p_n1;

	Person p_n3=p_n1;
	p_n3.m_printPersonalInfo();
	
	Student s_n1("Jane", 23, "high", "university of York",4, 87 );
	//s_n1.m_printPersonalInfo();

	Student* s_n2= new Student("Tom", 22,"high", "UNU", 4, 90);

	//s_n2->higherGPA(s_n1);		

	Teacher t_n1("Loa", 43, "high", "Computer Science",12);
	Teacher t_n2("Sofi", 33, "high", "Computer Science",6);

	//t_n1.lessExperience(t_n2);
	//t_n1.m_printPersonalInfo();
	
	delete s_n2;
	return 0;
}	
