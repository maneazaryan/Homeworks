#include <iostream>	

class Counter{
	private:
		int* m_num;
	public: 
		static int count;
		static int countD;
		Counter(int n=0):m_num(new int(n)){
			count++;
		}
		~Counter(){
			countD++;
			delete m_num;
			//std::cout<<"Deleted : "<<countD<<std::endl;
		}
		static void printCount(){
			std::cout<<"Created : "<<count<<std::endl;
		}
		static int avaible(){
			return count-countD;
		}
};

int Counter::count=0;
int Counter::countD=0;

void initObj(int n){
	for(int i=0; i<n; i++)
	{
		Counter n1(i+1);
		std::cout<<"currently avaible : "<< Counter::avaible()<<std::endl;
		Counter::printCount();
	}
}
int main()
{
	std::cout<<"Enter count of objects"<<std::endl;
	int n;
	std::cin>>n;
	initObj(n);
	Counter::printCount();
	std::cout<<"currently avaible : "<< Counter::avaible()<<std::endl;
	return 0;
}	
