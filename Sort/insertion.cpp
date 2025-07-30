#include <iostream>	
#include <vector>

void insertionSort(std::vector<int>& v, int n)
{
	int res;
	for(int i=1; i<n; i++)
	{
		int k=i-1;
		res=v[i];
		while(k>=0 && v[k]>res)
		{
			v[k+1]=v[k];
			k--;
		}
		v[k+1]=res;
	}
}
int main()
{
	std::vector<int>v={2,5,1,11,8,0,3,6,8,9};
	insertionSort(v, v.size());
	for(int a:v) std::cout<<a<<' ';
	return 0;
}	
