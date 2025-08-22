#include <iostream>
#include <memory>

int main(){
	std::shared_ptr<int>matrix[3][3];

	for(int i = 0 ; i<3; i++)
	{
		for(int j = 0 ; j<3 ; j++)
		{
			matrix[i][j]=std::make_shared<int>();
		}
	}

	std::cout<<matrix<<std::endl;
	std::cout<<matrix[0]<<std::endl;
	std::cout<<matrix[0][0]<<std::endl;
	std::cout<<*(matrix[0])<<std::endl;


	//std::shared_ptr<int>* row = matrix[0];
	//std::cout<<row<<std::endl;
	return 0;
}
