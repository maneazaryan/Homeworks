#pragma once
#include <iostream>
#include <string>
#include "person.h"
class Student:public Person{
	public:
		std::string m_university;
		int m_course ;
		int m_GPA;

		Student(std::string name, int age, std::string education,std::string university, int course, int GPA)
		:Person(name, age, education), m_university(university), m_course(course), m_GPA(GPA) {}
		~Student() override{}

		void m_printPersonalInfo()override;
		void higherGPA(const Student& other)const;
		
	private:
		bool operator >(const Student& other)const;
};
