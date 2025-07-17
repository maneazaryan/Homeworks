#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int main(int argc,char* argv[])
{
	int row , col;
	if(argc== 2 )
	{
		row=stoi(argv[1]);
		col=row;
	}else if(argc==3 )
	{
	        row = stoi(argv[1]);
		col = stoi(argv[2]);
	}else 
	{
		cout<<"error"<<endl;
		return 1;
	}
	if (row<=0 || col<=0) 
	{
		cout<<"error"<<endl;
		return 2;
	} 
	srand(time(0));
	vector<vector<int>>matrix(row,vector<int>(col)) ;
	for( int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			matrix[i][j]=rand()%100+1;
			cout<< matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
