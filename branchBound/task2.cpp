#include <iostream>	
#include <vector>

struct bestCase{
	public:
	std::vector<int>v ;
	int totalWeight;
	int totalAmount;
	
	bestCase() : v(0), totalWeight(0), totalAmount(0){}
	void print();
};
void bestCase::print()
{
	for(int i=0; i<v.size(); i++)
	{
		if(i!=v.size()-1) std::cout<<v[i]<<'+';
		else std::cout<<v[i]<<'='<<totalWeight<<std::endl;
	}
	std::cout<<"Total amount is: "<<totalAmount<<std::endl;
}

bestCase best;
void check(std::vector<int> W, std::vector<int> P, int max, int size , int a)
{
	if(a>=size)return;
	for(int i=0; i<size; i++)
	{
		int amount=0;
		int weight=0;
		bestCase n1;
		for(int k=i; k<size;k++)
		{
			if(weight+W[k]<=max)
			{
				weight+=W[k];
				n1.v.push_back(W[k]);
				amount+=P[k];
                         }
		}
		n1.totalWeight=weight;
		n1.totalAmount= amount;
		if((n1.totalWeight<=max && n1.totalAmount==best.totalAmount) || n1.totalAmount>best.totalAmount)
		{
			best=n1;
		}
// հա տ ուկ դեպ քերի հա մա ր
		int amount2=0;
		int weight2=0;
		bestCase n2;
		for(int k=i; k>=0 ;k--)
		{
			if(weight2+W[k]<=max)
			{
				weight2+=W[k];
				n2.v.push_back(W[k]);
				amount2+=P[k];
                         }
		}
		n2.totalWeight=weight2;
		n2.totalAmount= amount2;
		if((n2.totalWeight<=max && n2.totalAmount==best.totalAmount) || n2.totalAmount>best.totalAmount)
		{
			best=n2;
		}
	}
	check(W,P,max,size,a+1);
}
int main()
{
	std::vector<int> Weightes={2,3,4};
	std::vector<int> Prices={1000,1400,1600};
	
	int max=5;
	check(Weightes, Prices, max, Weightes.size(),0);
	best.print();
	return 0;
}	
