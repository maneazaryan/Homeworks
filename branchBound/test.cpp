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
bool solution(vector<vector<int>>& s)
{
	bool checking;
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s[i].size(); j++){
			if(s[i][j]==0){
				for(int a=1; a<=4 ; a++){
					checking= true;
					for(int h=0; h<s.size(); h++)
					{
						if(s[h][j]==a || s[i][h]==a) 
						{
							checking=false;
							break; 
						}
					}
					if(checking ) 
					{
						s[i][j]=a;
						if(solution(s)) return true;
						else s[i][j]=0;
					}
				}
				return false; 
			}
		}
	}
	return true;
}
int main()
{
	vector<vector<int>> sudoku(4,vector<int>(4,0));
	sudoku[0][0]=4;
	sudoku[1][2]=2;
	sudoku[2][1]=1;
	sudoku[3][3]=3;
	solution(sudoku);
	print(sudoku);
	return 0;
}	
