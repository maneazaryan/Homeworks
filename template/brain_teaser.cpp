#include <iostream>	
#include <memory>
class A{
	int value;
	public:
		A(){value=0;};
	friend std::ostream& operator<<(std::ostream& os, const A& a)
	{
		os<<a.value;
		return os;
	}
};
int main()
{
	std::shared_ptr<A> matrix[3][3];
	for(int i=0 ; i<3; i++)
	{
		for(int j=0 ; j<3; j++)
		{
			matrix[i][j]=std::make_shared<A>();
		}		
	}
	
	std::cout<<"address of matrix    : "<<matrix<<std::endl;
	std::cout<<"address of matrix[0] : "<<matrix[0]<<std::endl;

	std::shared_ptr<A>* line = matrix[0];
	std::cout<<"address of line[0]   : "<<(line)<<std::endl;

	std::cout<<std::endl;
	std::shared_ptr<A>* element = line;
	std::cout<<"address of matrix[0][0]  : " << matrix[0][0]<<std::endl;
	std::cout<<"address of element[0][0] : " << *element<<" *line " << *line <<std::endl;
	std::cout<<"address of matrix[0][1]  : " << matrix[0][1] << std::endl;
	std::cout<<"address of element[0][1] : " << *(element+1) << std::endl;

	std::cout<<std::endl;
	std::cout<<"real obj"<<std::endl;
	std::cout<<"obj[0][0] : "<<*(element->get())<<' '<<*(*element)<<std::endl ;
	std::cout<<"obj[0][1] : "<<*((element+1)->get())<<std::endl;
	std::cout<<std::endl;


//	std::shared_ptr<A>* line1= matrix[1];
//	std::cout<<"address of line[1] : "<<(line1)<<std::endl;
	return 0;
}	
