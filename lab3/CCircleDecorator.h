#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "CShapeDecorator.h"

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(sf::Shape*);
	float GetArea() override;
	float GetPerimeter() override;

	void Display(sf::RenderWindow& window) const override;
	std::string ToString() override;
private:
	sf::Shape* m_circle;
};

