#include <iostream>	
#include <vector>
#include <ctime>
#include <cstdlib>

void initVector(std::vector<int>& v, int size)
{
	srand(time(0));
	for(int i=0; i<size; i++) v[i]=rand()%100;
}

int pivotSort(std::vector<int>& v,int begin,  int end )
{
	int pIndex=(end-begin)/2+begin;
	int pivot=v[pIndex];
	int b=begin;
	int e=end;

	while(b<=e){
		while (v[b]<pivot) b++;
		while (v[e]>pivot) e--;
		
		if(b<=e){
		int res= v[b];
		v[b]=v[e];
		v[e]=res;
		b++;
		e--;
		}
	}	
	return b;
}

void quickSort(std::vector<int>& v, int begin, int end)
{
	if(begin>=end) return;
	int p=pivotSort(v,begin, end);
	quickSort(v, begin , p-1);
	quickSort(v, p, end);
	
}

int main()
{
	int size;
	std::cout<<"Enter size of the array"<<std::endl;
	std::cin>>size;
	std::vector<int> v(size);

	initVector(v, size);
	for(int a:v) std::cout<<a<<' ';
	std::cout<<"Before"<<std::endl;

	quickSort(v,0,size-1);
	for(int a:v) std::cout<<a<<' ';

	return 0;
}	
