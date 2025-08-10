#include "canvas.h"
void Canvas::Draw()
{
	for(int i =0 ; i<m_shape.size(); i++)
	{
		m_shape[i]->Draw(*this);
	}
        for(int i=0; i<m_row; i++){
                for(int j=0; j<m_col; j++){
                        std::cout<<m_v[i][j];
                }
                std::cout<<std::endl;
        }
}
std::vector<char>& Canvas::operator[](int index) 
{
        return m_v[index];
}
int Canvas::getRow()const {return m_row;}
int Canvas::getCol()const {return m_col;}
void Canvas::AddShape(Shape* shape)
{
        m_shape.push_back(shape);
}

