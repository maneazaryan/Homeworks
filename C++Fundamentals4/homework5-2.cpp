#include <iostream>
#include <string>
#include <vector>
using namespace std;
	
struct StudentProfile{
		public:
		const string sName ;
		const int nStudentID;
		const int nBirthYear;
		vector<int>& vecOfGrades;
		StudentProfile(const string a, const int b , const int c , vector<int>&d) : sName(a), nStudentID(b), nBirthYear(c), vecOfGrades(d){
		}
		int averageGrade()
		{
			int n = vecOfGrades.size();
			int sum=0;
			for(int i=0; i<n; i++)
			{
				sum+=vecOfGrades[i];
			}	
			return sum/n;
		}	
		void printProfile()
		{
			cout<<"Name "<<sName<<endl;
			cout<<"Id "<<nStudentID<<endl;
			cout<<"Birth Year "<<nBirthYear<<endl;
			cout<<"Average: "<<averageGrade()<<endl;
		}
};
int main(){
	int n;
	cout<<"Please enter the number of grades"<<endl;
	cin>> n;
	vector<int>nums(n);
	for(int i =0; i<n ; i++)
	{
		cin>>nums[i];
	}
	StudentProfile num1("Anna", 12345, 1990, nums);
	num1.printProfile();
	return 0;
}	
