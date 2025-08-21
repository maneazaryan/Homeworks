#include <iostream>	
#include <algorithm>
#include <vector>
int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12};
	std::for_each(v.begin(), v.end(), [](int a){
		if(a%2==0) std::cout<<a<<' ';
	});	
	return 0;
}	
