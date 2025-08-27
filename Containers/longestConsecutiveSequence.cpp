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
int find()
{
	std::vector<int > v= initArr();
	std::map<int, int> m;

	for( int a : v) m[a]=1;
	int count , max=0;
	for(auto it = m.begin(); it!=m.end(); it++)
	{
		count=1;
		int a = it->first;
		while(m.find(a+1)!= m.end())
		{
			count++;
			a++;
		}
		if(count > max) max = count;
	//	m[it->first]=count;
	}
	return max;
}
int main()
{
	std::cout<<find()<<": Longest Consecutive Sequence "<<std::endl;	
	return 0;
}	
