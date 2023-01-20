#include "CRectangleCreator.h"
#include "CRectangleDecorator.h"

CShapeDecorator* CRectangleCreator::CreateShape(std::smatch& match)
{
    float x1 = std::stof(match[1]);
    float y1 = std::stof(match[2]);
    float x2 = std::stof(match[3]);
    float y2 = std::stof(match[4]);

    float w = std::abs(x1 - x2);
    float h = std::abs(y1 - y2);

    sf::RectangleShape* rectangle = new sf::RectangleShape();

    rectangle->setSize(sf::Vector2f(w, h));
    rectangle->setPosition(sf::Vector2f(x1, y1));

    return new CRectangleDecorator(rectangle);
}
