#include <numbers>
#include "CCircleDecorator.h"

CCircleDecorator::CCircleDecorator(sf::Shape* shape) : m_circle(shape)
{
}

float CCircleDecorator::GetArea()
{
	sf::CircleShape* circle = static_cast<sf::CircleShape*>(m_circle);
	
	float radius = circle->getRadius();
	float area = std::numbers::pi * std::pow(radius, 2);

	return area;
}

float CCircleDecorator::GetPerimeter()
{
	sf::CircleShape* circle = static_cast<sf::CircleShape*>(m_circle);

	float radius = circle->getRadius();
	float perimeter = std::numbers::pi * 2 * radius;

	return perimeter;
}
