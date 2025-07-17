#include <iostream>
#include <vector>
using namespace std;

struct CoffeeMachine{
	public:
		vector<string>& products;
		vector<int>& prices;

		void printPriceList(); 
		CoffeeMachine(vector<string>& a, vector<int>& b) : products(a), prices(b){}
		~CoffeeMachine(){};
};

struct Order{
	public:
	string &coffeeOrder;
	int &cashIn;
	CoffeeMachine& machine;
	Order(string &a, int &b, CoffeeMachine& c) : coffeeOrder(a), cashIn(b), machine(c) {}
	int  check();
	~Order(){};
};

void CoffeeMachine::printPriceList()
	{
		for(int i = 0; i< products.size(); i++)
		{
			cout<<i+1<< " "<<products[i]<<" " << prices[i]<< endl;
		}
	}
int Order::check()
	{
		for(int i=0; i< machine.products.size(); i++)
		{
			if(coffeeOrder== machine.products[i])
			{
				if(cashIn==machine.prices[i])
				{ 
					cout<<"Your order is accepted. You don't have any change."<<endl;
				}
				if(cashIn>machine.prices[i])
					{
					cout<<"Your order is accepted "<< cashIn-machine.prices[i]<< "  please your change";	
				}
				else if (cashIn<machine.prices[i])
				{
					cout<<"Your order is not accepted " << cashIn-machine.prices[i]<< "Not enough money";
				}
				return 0;
				
			}
		}
                cout<< "Error"<<endl;
		return 1;		
                       
	}

int main()
{
	vector<string> name ={"Espresso", "Cappuccino", "Latte", "Americano", "Affogato"};
	vector<int> price = {100, 200, 200, 150, 150};
	string order;
	int money;

	CoffeeMachine list1(name, price);
	list1.printPriceList();

	cout<<"please enter the order"<<endl;
	cin>>order;
	cin>>money;
	Order myOrder(order,money,list1);
	myOrder.check();
	return 0; 

}
