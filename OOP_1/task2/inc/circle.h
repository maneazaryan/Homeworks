#pragma once	
#include "shape.h"
#include "canvas.h"
class Circle:public Shape{
        private:
                int m_x, m_y,m_radius;
        public:
                Circle(int x,int y,int radius) : m_x(x) , m_y(y), m_radius(radius){}
                void Draw(Canvas& canvas)override;
};

