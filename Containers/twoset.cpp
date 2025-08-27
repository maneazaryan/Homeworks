#include <iostream>	
#include <vector>
#include <set>

std::vector<int> initVector()
{
	std::cout<<"enter size of array"<<std::endl;
	int size, num;
	std::cin>>size;
	std::vector<int> v;
	std::cout<<"enter elements of array"<<std::endl;
	while(size>0)
	{
		std::cin>>num;
		v.push_back(num);
		size--;
	}
	return v;
}
void getSet( const std::vector<int>& v, std::set<int>& s)
{
	for(int i =0 ; i<v.size(); i++)
	{
		s.insert(v[i]);
	}
}
std::set<int> initset(const std::vector<int>& v)
{
	std::set<int> s;
	for(int i = 0 ; i<v.size(); i++)
	{
		s.insert(v[i]);
	}
	return s;
}
int main()
{	
	std::vector<int> v1=initVector();
	std::vector<int> v2=initVector();	
	std::set<int> s;
	getSet(v1, s);
	getSet(v2, s);

	for(int  a : s ) std::cout<<a << ' ';
	std::cout<<std::endl;
// version 2
	std::set<int> s1 = initset(v1);
	std::set<int> s2 = initset(v2);

	s1.merge(s2);
	for(int a : s1) std::cout<<a << ' ';
	return 0;
}	
