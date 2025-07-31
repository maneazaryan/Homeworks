#include <iostream>	
#include <vector>
using namespace std;

void print(const vector<vector<int>>& sudoku)
{

	for(int i=0; i<sudoku.size(); i++)
	{
		for(int j=0; j<sudoku[i].size(); j++)
		{
			std::cout<<sudoku[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
}
void solution(vector<vector<int>>& s, int a)
{
	if(a>4)return;
	bool checking=true;
	for(int i=0; i<s.size(); i++)
	{
		for(int j=0; j<s[i].size(); j++)
		{
			if(s[i][j]==0){
				for(int h=0; h<s.size(); h++)
				{
					if(s[h][j]==a || s[i][h]==a) 
					{
						checking=false;
						break; 
					}
					else checking= true;
				}
				if(checking) 
				{
					s[i][j]=a;
					solution(s, a+1);
				}
			}
		}
	}
}
int main()
{
	vector<vector<int>> sudoku(4,vector<int>(4,0));
	sudoku[0][0]=1;
	sudoku[1][2]=2;
	sudoku[2][1]=1;
	sudoku[3][3]=3;
	solution(sudoku, 1);
	print(sudoku);
	return 0;
}	
