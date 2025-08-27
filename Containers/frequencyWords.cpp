#include <iostream>
#include <string>
#include <map>
#include <sstream>
void string_to_arr(std::string& text)
{
	std::string word;
	std::stringstream ss(text);
	std::map<std::string, int> m;
	while(ss>>word)
	{	
		int count =1;
		auto it = m.find(word);
		if(it == m.end())
		{
			m[word]=count;		
		}
		else {
			it->second++;	
		}
	}
	for(auto [key,value] : m)
		std::cout<<key<<','<<value<<std::endl;
}
int main()
{
	std::cout <<"Enter a text "<< std::endl;
	std::string text;
	std::getline(std::cin,text);
	string_to_arr(text);
	return 0;
}	
