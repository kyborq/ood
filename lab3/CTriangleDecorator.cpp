#include "CTriangleDecorator.h"

#include <iostream>
#include <sstream>

const std::string PERIMETER = "P=";
const std::string SQUARE = "; S=";

CTriangleDecorator::CTriangleDecorator(sf::Shape* shape) : m_triangle(shape)
{
}

float CTriangleDecorator::GetArea() const
{
	sf::ConvexShape* triangle = static_cast<sf::ConvexShape*>(m_triangle);

	sf::Vector2f a = triangle->getPoint(0);
	sf::Vector2f b = triangle->getPoint(1);
	sf::Vector2f c = triangle->getPoint(2);


	float area = std::fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;

	return area;
}

float CTriangleDecorator::GetPerimeter() const
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

std::string CTriangleDecorator::Accept(IVisitor& visitor) const
{
	visitor.VisitShape(*this);
}

void CTriangleDecorator::Display(sf::RenderWindow& window) const
{
	sf::ConvexShape* triangle = static_cast<sf::ConvexShape*>(m_triangle);
	window.draw(*triangle);
}

std::string CTriangleDecorator::ToString()
{
	std::ostringstream strm;
	strm << SQUARE << GetArea() << PERIMETER << GetPerimeter();

	return strm.str();
}
