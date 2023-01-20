#include "CTriangleCreator.h"
#include "CTriangleDecorator.h"

CShapeDecorator* CTriangleCreator::CreateShape(std::smatch& match)
{
    float x1 = std::stof(match[1]);
    float y1 = std::stof(match[2]);
    float x2 = std::stof(match[3]);
    float y2 = std::stof(match[4]);
    float x3 = std::stof(match[5]);
    float y3 = std::stof(match[6]);

    sf::ConvexShape* triangle = new sf::ConvexShape();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(x1, y1));
    triangle->setPoint(1, sf::Vector2f(x2, y2));
    triangle->setPoint(2, sf::Vector2f(x3, y3));

    return new CTriangleDecorator(triangle);
}
