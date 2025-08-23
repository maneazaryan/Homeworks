#include <iostream>	
#include <vector>

struct bestCase{
	public:
	std::vector<int> v;
	int sum;
	void print();
	
	bestCase() : v(0), sum(0){}
};
void bestCase::print(){
	for(int a=0; a< v.size(); a++) {
		if(a!=v.size()-1)std::cout << v[a] << '+';
		else std::cout<< v[a] << '='<< sum <<std::endl;
	}
}
void checkSum(std::vector<int>& v, int n, int max, int a)
{
	if(a>=n) return;
	for(int i=0; i<n ; i++)
	{
		int sum =v[i];
		bestCase n1;
		n1.v.push_back(v[i]);
		for(int k=i+1+a; k<n; k++){
			if(sum+v[k]<=max){
				sum+=v[k];
				n1.v.push_back(v[k]);
			}
		}
		if(sum==max) {
			n1.sum=sum;
			n1.print();
		}
	}
	checkSum(v,n,max , a+1);
}

void reverseV(std::vector<int>&v, int size, int max)
{
	std::vector<int>rV(size);
	for(int i=0; i<size; i++)
	{
		rV[i]=v[size-1-i];
	}
	//for(int a: rV) std::cout<< a<< ' ';
	checkSum(rV, size, max ,1);
}
int main()
{
	std::vector<int> v= {3,5,6,7,8};
	int maxSum=12;
	checkSum(v, v.size(), maxSum ,0);
	reverseV(v, v.size(),maxSum);
	return 0;
}	
