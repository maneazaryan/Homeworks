#include <iostream>	
#include <vector>
#include <map>

std::vector<int> initArr()
{
	std::vector<int> v;
	int size , num ;
	std::cout<<"enter size of array "<<std::endl;
	std::cin>>size;
	std::cout<<"enter "<<size<< "  elements  "<<std::endl;
	while(size>0)
	{	
		std::cin>>num ;
		v.push_back(num);
		size--;
	}
	return v;
}
int main()
{
	std::vector<int> v = initArr();
	int k ;
	std::cout<<"Enter k "<<std::endl ;
	std::cin>>k ;

	std::map<int , int> m ;
	int count;
	for(int i =0 ; i<v.size(); i++)
	{
		count =1;
		if(m.find(v[i])==m.end())
		{
			m.insert({v[i],count});
		}
		else{
			count= m.at(v[i]);
			count++;	
			m[v[i]]=count;
		}
	}
	auto c = [](const int& a , const int& b ){return a>b;};
	std::multimap<int , int , decltype(c)> mm(c) ;
	for(auto [key , value] : m )
		mm.insert({value, key});	
	for(auto it = mm.begin(); it!=mm.end() && k>0 ; it++, k-- ) 
		std::cout<<it->second <<' ';
	return 0;
}	
