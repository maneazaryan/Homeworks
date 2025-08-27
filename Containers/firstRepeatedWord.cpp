#include <iostream>	
#include <vector>
#include <string>
#include <unordered_set>
void printF_Word(std::vector<std::string>& v)
{
	std::unordered_set<std::string > t;
	for(int i = 0 ; i < v.size(); i++)
	{
		if(t.find(v[i])==t.end())
		{
			t.insert(v[i]);
		}
		else {
			std::cout<<"First Repeated Word is : "<<v[i]<<std::endl;
			return ;
		}
	}
	std::cout<<"None"<<std::endl;

}
int main()
{
	std::cout<<"Enter count of word"<<std::endl;
	int size;
	std::string word;
	std::cin>>size;
	std::vector<std::string>v;
	std::cout<<"Enter "<<size<<" word"<<std::endl;
	while(size>0)
	{
		size--;
		std::cin>>word;
		v.push_back(word);
	}
	printF_Word(v);	
	return 0;
}	
