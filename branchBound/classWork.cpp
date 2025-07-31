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
	for(int a:v) {
		if(a!=v[v.size()-1])std::cout << a << '+';
		else std::cout<< a << '='<< sum <<std::endl;
	}
}

bestCase best;

void sum(std::vector<int>& v, int n, int max, int a)
{
	if(a>=n) return;
	for(int i=0; i<n ; i++)
	{
		int sum =v[i];
		int k=i+1+a;
		bestCase n1;
		n1.v.push_back(v[i]);
		while(sum<=max && k<n){
			if(sum+v[k]<=max){
				sum+=v[k];
				n1.v.push_back(v[k]);
				k++;
			}else{
				k++;
				}
		}
		n1.sum=sum;
		if(n1.sum>best.sum || (n1.sum==best.sum && n1.v.size()<best.v.size())){
		best= n1;
		}
	}
	sum(v,n,max , a+1);
}

int main()
{
	std::vector<int> v= {2,3,5,8};
	int maxSum=10;
	sum(v, v.size(),maxSum,0);
	best.print();
	return 0;
}	
