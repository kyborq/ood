#pragma once
class CShapeDecorator
{
public:
	~CShapeDecorator() {};
	virtual float GetArea() = 0;
	virtual float GetPerimeter() = 0;
};

