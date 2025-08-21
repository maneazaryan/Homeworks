#include <iostream>	
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> fruits = {"apple", "banana", "apricot", "cherry"};
	char startLetter = 'a';

	int count = std::count_if(fruits.begin(), fruits.end(),[startLetter](const std::string& a){
		if(a[0]==startLetter) return true;
		else return false;
	} );
	std::cout << count;
	return 0;
}	
