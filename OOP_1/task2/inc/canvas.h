#pragma once
#include <iostream>
#include <vector>
#include "shape.h"
class Canvas{
        private:
                int m_row, m_col;
                std::vector<std::vector<char>> m_v;
		std::vector<Shape*> m_shape;
        public:
                Canvas(int row=20, int col=40 ): m_row(row), m_col(col),m_v(m_row,std::vector<char>(m_col,'-')) {}
		~Canvas()
		{
			for(int i=0; i<m_shape.size();i++)
				delete m_shape[i];
		}
                void Draw(); 
                std::vector<char>& operator[](int index);
                int getRow()const ;
                int getCol()const ; 
                void AddShape(Shape* shape);
};
