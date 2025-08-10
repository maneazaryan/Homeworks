#include "cross.h"
void Cross::Draw(Canvas& canvas){
	for(int i=m_y-m_size; i<=m_y+m_size; i++){
		for(int j=m_x-m_size; j<=m_x+m_size; j++){

			canvas[i][m_x]='+';
			canvas[m_y][j]='+';
		}
	}
}
