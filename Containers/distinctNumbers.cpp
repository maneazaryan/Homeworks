#include <iostream>	
#include <vector>
#include <unordered_set>
int count(std::vector<int>& v)
{
	int count= 0 ;
	std::unordered_set<int> s;
	
	for(int i = 0 ; i<v.size(); i++)
	{
		if(s.find(v[i]) == s.end() ) {
			s.insert(v[i]);
			count++;
		}
	}
	return count;
}
void initArr(){
	int size,num;
	std::cout<<"Enter size of array"<<std::endl;
	std::cin>>size;
	std::vector<int> v ;
	std::cout<<"Enter "<<size<<" elements"<<std::endl;
	while(size>0)
	{
		size--;	
		std::cin>>num;
		v.push_back(num);
	}	
	for(const int& a: v)
		std::cout<<a<<' ';
	std::cout<<std::endl;
	std::cout<<count(v);
}
int main()
{
	initArr();
	return 0;
}	
