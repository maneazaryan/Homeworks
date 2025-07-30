#include <iostream>	
#include <vector>
void selectionSort(std::vector<int>& v, int n)
{
	int min ;
	for(int i =0; i<n; i++)
	{
		min=i;
		for(int j=i+1; j<n; j++)
		{
			if(v[j]<v[min])min=j;
		}
		if(i!=min)
		{
			int res=v[i];
			v[i]=v[min];
			v[min]=res;
		}
	}
}

int main()
{
	std::vector<int>v = {4,2,7,9,6,1,5,0};
	selectionSort(v, v.size());
	for(int a:v) std::cout<<a<<' ';
	return 0;
}
