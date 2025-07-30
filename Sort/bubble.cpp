#include <iostream>	
#include <vector>

void bubbleSort(std::vector<int>& v, int n)
{
	int res;
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i;j++)
		{
			res=v[j];
			if(v[j]>v[j+1])
			{
				v[j]=v[j+1];
				v[j+1]=res;
			}
		}
	}
}
void initVector(std::vector<int>& v, int n)
{
	if(n<=0) return;
	int m;
	std::cin>>m;
	v[v.size()-n]=m;
	initVector(v, n-1);
}
int main()
{
	int n;
	std::cout<<"Enter size of the array"<<std::endl;
	std::cin>>n;
	std::vector<int> v(n);

	std::cout<<"Enter member of the array"<<std::endl;
	initVector(v,n);

	bubbleSort(v, n);
	for (int a : v) std::cout<< a<< ' ';
	return 0;
}	
