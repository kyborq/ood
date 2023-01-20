#include <numbers>
#include "CCircleDecorator.h"
#include <sstream>

CCircleDecorator::CCircleDecorator(sf::Shape* shape) : m_circle(shape)
{
}

float CCircleDecorator::GetArea() const
{
	sf::CircleShape* circle = static_cast<sf::CircleShape*>(m_circle);
	
	float radius = circle->getRadius();
	float area = std::numbers::pi * std::pow(radius, 2);

	return area;
}

std::string CCircleDecorator::Accept(IVisitor& visitor) const
{
	visitor.VisitShape(*this);
}

float CCircleDecorator::GetPerimeter() const
{
	sf::CircleShape* circle = static_cast<sf::CircleShape*>(m_circle);

	float radius = circle->getRadius();
	float perimeter = std::numbers::pi * 2 * radius;

	return perimeter;
}

void CCircleDecorator::Display(sf::RenderWindow& window) const
{
	sf::CircleShape* circle = static_cast<sf::CircleShape*>(m_circle);
	window.draw(*circle);
}

std::string CCircleDecorator::ToString()
{
	std::ostringstream strm;
	strm << "S:" << GetArea() << "; P:" << GetPerimeter() << std::endl;

	return strm.str();
}

