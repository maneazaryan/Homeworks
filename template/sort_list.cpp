#include <iostream>	
#include <vector>
#include <algorithm>
#include <string>

/*bool rule(const std::string& a , const std::string& b)
{
	if(a.size()!=b.size())
	{
		return a.size()<b.size();
	}
	return a<b;
}	*/
int main()
{
	std::vector<std::string> names = {"Bob", "Alex", "Christina", "Zoe", "Anna"};
	for(std::string a : names)
		std::cout<< a <<' ';
	std::cout<<std::endl;

	std::sort(names.begin(), names.end(), [](const std::string& a , const std::string& b){
			if(a.size()!=b.size())
			{
				return a.size()<b.size();
			}
			return a<b;
		} 
	);
	for(std::string a : names)
		std::cout<< a <<' ';
	return 0;
}	
