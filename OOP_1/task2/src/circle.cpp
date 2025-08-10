#include "circle.h"
void Circle::Draw(Canvas& canvas){
	for(int i=m_y-m_radius; i<=m_y+m_radius; i++){
		for(int j=m_x-m_radius; j<=m_x+m_radius ; j++){
			if(j<0 || i<0 || i >= canvas.getRow() || j>=canvas.getCol())
			{ 
				std::cout<<"Error: out of range"<<std::endl;
				return;
			}
			int dx = j - m_x;
			int dy = i - m_y;
			double adj_dx = dx * 1.0;
			if (adj_dx*adj_dx + dy*dy <= m_radius * m_radius) {
				canvas[i][j] = 'O';
			}   
		}   
	}   
}   
