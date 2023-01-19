#pragma once
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"

class CTriangleDecorator : public CShapeDecorator
{
public:
	CTriangleDecorator(sf::Shape*);
	float GetArea() override;
	float GetPerimeter() override;
private:
	sf::Shape* m_triangle;
};

