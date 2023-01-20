#pragma once
#include "IVisitor.h"

class CShapeDecorator
{
public:
	~CShapeDecorator() {};
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string Accept(IVisitor& visitor) const = 0;

	virtual void Display(sf::RenderWindow& window) const = 0;
	virtual std::string ToString() = 0;
};

