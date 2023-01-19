#include "CRectangleDecorator.h"

CRectangleDecorator::CRectangleDecorator(sf::Shape* shape) : m_rectangle(shape)
{
}

float CRectangleDecorator::GetArea()
{
	sf::RectangleShape* rectangle = static_cast<sf::RectangleShape*>(m_rectangle);

	float x = rectangle->getSize().x;
	float y = rectangle->getSize().y;

	return x * y;
}

float CRectangleDecorator::GetPerimeter()
{
	sf::RectangleShape* rectangle = static_cast<sf::RectangleShape*>(m_rectangle);

	float x = rectangle->getSize().x;
	float y = rectangle->getSize().y;

	return x * 2 + y * 2;
}
