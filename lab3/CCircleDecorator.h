#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "CShapeDecorator.h"
#include "IVisitor.h"

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(sf::Shape*);
	float GetArea() const override;
	float GetPerimeter() const override;

	void Display(sf::RenderWindow& window) const override;
	std::string ToString() override;
	std::string Accept(IVisitor& visitor) const override;
private:
	sf::Shape* m_circle;
};

