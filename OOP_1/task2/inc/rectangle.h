#pragma once
#include "shape.h"
#include "canvas.h"
class Rectangle:public Shape{
        private:
                int m_x, m_y;
                int m_width, m_height;
        public:
                Rectangle(int x, int y , int width, int height):m_x(x), m_y(y), m_width(width), m_height(height){}
                void Draw(Canvas& canvas)override;
};
