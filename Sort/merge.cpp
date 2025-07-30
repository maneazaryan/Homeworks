#include <iostream>	
#include <vector>
#include <ctime>
#include <cstdlib>

void initVector(std::vector<int>& v, int size)
{
	srand(time(0));
	for(int i =0; i<size; i++) v[i]=rand()%101;
}
void merge(std::vector<int>& v, int begin , int mid , int end)
{
	int e =0;
	int b=0;
	int n=begin;

	int sizeB=mid-begin+1;
	int sizeE=end-mid;
	std::vector<int>B (sizeB);
	std::vector<int>E (sizeE);
	
	for(int i =0; i<sizeB; i++) B[i]=v[begin+i];
	for(int i =0; i<sizeE; i++) E[i]=v[mid+1+i];
	
	while(b<sizeB && e<sizeE){
		if(B[b]<= E[e] ){
			v[n]=B[b];
			b++;
			n++;
		}else{
			v[n]=E[e];
			e++;
			n++;
		}
	}
	while(b<sizeB){
		v[n]=B[b];
		b++;
		n++;
	}
	while(e<sizeE){
		v[n]=E[e];
		e++;
		n++;
	}
}

void sortMerge(std::vector<int>& v, int begin, int end)
{
	if(begin>=end) return;
	int mid = (end-begin)/2 + begin;
	sortMerge(v, begin , mid);
	sortMerge(v, mid+1 , end);	
	merge(v , begin, mid, end);
}
int main()
{	
	int size;
	std::cout<<"Enter size of arr"<<std::endl;
	std::cin>>size;
	std::vector<int> v(size);
	initVector(v,size);
	sortMerge(v,0,size-1);
	
	for(int a:v) std::cout<<a<<' ';

	return 0;
}	
