#pragma once
#include <iostream>	
#include <string>
#include "person.h"
class Teacher:public Person{
	public : 
		std::string m_subject;
		int m_experience;
		Teacher(std::string name, int age, std::string education, std::string subject, int experience)
		:Person(name, age, education), m_subject(subject), m_experience(experience){}	
		
		~Teacher() override {}
		void m_printPersonalInfo() override;
		void lessExperience(const Teacher& other)const;
		bool operator < (const Teacher& other) const;
};
