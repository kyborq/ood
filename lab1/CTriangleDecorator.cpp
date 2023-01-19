#include "CTriangleDecorator.h"

#include <iostream>

CTriangleDecorator::CTriangleDecorator(sf::Shape* shape) : m_triangle(shape)
{
}

float CTriangleDecorator::GetArea()
{
	sf::ConvexShape* triangle = static_cast<sf::ConvexShape*>(m_triangle);

	sf::Vector2f a = triangle->getPoint(0);
	sf::Vector2f b = triangle->getPoint(1);
	sf::Vector2f c = triangle->getPoint(2);

	std::cout << "B-" << std::fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2 << std::endl;

	float area = std::fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;

	return area;
}

float CTriangleDecorator::GetPerimeter()
{
	sf::ConvexShape* triangle = static_cast<sf::ConvexShape*>(m_triangle);

	sf::Vector2f a = triangle->getPoint(0);
	sf::Vector2f b = triangle->getPoint(1);
	sf::Vector2f c = triangle->getPoint(2);

	float ab = std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
	float ac = std::sqrt(std::pow(a.x - c.x, 2) + std::pow(a.y - c.y, 2));
	float bc = std::sqrt(std::pow(b.x - c.x, 2) + std::pow(b.y - c.y, 2));

	float perimeter = ab + ac + bc;

	return perimeter;
}
