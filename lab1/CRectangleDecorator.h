#pragma once
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"

class CRectangleDecorator : public CShapeDecorator
{
public:
	CRectangleDecorator(sf::Shape*);
	float GetArea() override;
	float GetPerimeter() override;
private:
	sf::Shape* m_rectangle;
};
