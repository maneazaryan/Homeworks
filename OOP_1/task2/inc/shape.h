#pragma once
class Canvas;
class Shape
{
	public:
	virtual ~Shape(){};
	virtual void Draw(Canvas& canvas)=0;
}; 
