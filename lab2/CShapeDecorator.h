#pragma once
class CShapeDecorator
{
public:
	~CShapeDecorator() {};
	virtual float GetArea() = 0;
	virtual float GetPerimeter() = 0;

	virtual void Display(sf::RenderWindow& window) const = 0;
	virtual std::string ToString() = 0;
};

