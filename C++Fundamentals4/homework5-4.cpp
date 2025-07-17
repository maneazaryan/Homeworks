#include <iostream>
using namespace std;

struct Calculator{
	double& number1;
	double& number2;
	char& oper;
	bool bMemorize;
	double memory;
	double add();
	double sub();
	double mult();
	double div();
	void printmemory();
	Calculator(double& a , double& b, char& c, bool m):number1(a), number2(b), oper(c),bMemorize(m){}
	
};

double Calculator::add()
{
	double res=number1+number2;
	if(!bMemorize) memory=res;	
	return res;
}
double Calculator::sub()
{
	double res=number1-number2;
	if(!bMemorize) memory=res;	
	return res;
}
double Calculator::mult()
{
	double res=number1*number2;
	if(!bMemorize) memory=res;	
	return res;
}
double Calculator::div()
{	
	if(number2==0) return 1;
	double res=number1/number2;
	if(!bMemorize) memory=res;	
	return res;
}
void Calculator::printmemory()
{
	cout<<"Memory: "<<memory<< endl;
}
int main()
{	
	double num1 , num2;
	char oper;
	cin>>num1>>oper>>num2;
	Calculator operation1(num1 , num2, oper, false);
	double result =0;
	if (oper=='+') result= operation1.add();
	else if (oper=='-') result=operation1.sub();
	else if (oper=='/') result=operation1.div();
	else if (oper=='*') result=operation1.mult();
	else return 1;
	cout<<result<<endl;
	operation1.printmemory();	
}	
