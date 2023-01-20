#include "CCircleCreator.h"
#include "CCircleDecorator.h"

CShapeDecorator* CCircleCreator::CreateShape(std::smatch& match)
{
    float x = std::stof(match[1]);
    float y = std::stof(match[2]);
    float radius = std::stof(match[3]);

    sf::CircleShape* circle = new sf::CircleShape();

    circle->setRadius(radius);
    circle->setPosition(x - radius, y - radius);

    return new CCircleDecorator(circle);
}
