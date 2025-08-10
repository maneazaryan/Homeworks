#include "rectangle.h"
void Rectangle::Draw(Canvas& canvas){
	for(int i=m_y; i<m_y+m_height; i++){
		for(int j=m_x; j<m_x+m_width; j++){
			canvas[i][j]='#';
		}   
	}   
}   
