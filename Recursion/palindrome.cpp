#include <iostream>	
#include <string>

int palindrome(std::string& text, int n)
{
	if(n>=text.size()/2 ) return 1;
	if(text[n]==text[text.size()-1-n])
	{
		return palindrome(text, n+1);
	} else return 0;
}
int main()
{
	std::string text;
	std::cout<<"enter a text"<<std::endl;
	std::cin>>text;
	std::cout<<palindrome(text,0)<<std::endl;
	return 0;
}
