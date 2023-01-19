#pragma once
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(sf::Shape*);
	float GetArea() override;
	float GetPerimeter() override;
private:
	sf::Shape* m_circle;
};

