#pragma once
#include "shape.h"
#include "canvas.h"
class Cross:public Shape{
        private:
                int m_x, m_y,m_size;
        public:
                Cross(int x,int y,int size) : m_x(x) , m_y(y), m_size(size){}
                void Draw(Canvas& canvas)override;
};
