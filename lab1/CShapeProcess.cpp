#include <string>
#include <regex>

#include "CShapeProcess.h"
#include "CShapeDecorator.h"
#include "CTriangleDecorator.h"
#include "CRectangleDecorator.h"
#include "CCircleDecorator.h"

const std::string TRIANGLE_REGEX = "TRIANGLE: P1=(.+),(.+); P2=(.+),(.+); P3:(.+),(.+)";
const std::string RECTANGLE_REGEX = "RECTANGLE: P1=(.+),(.+); P2=(.+),(.+)";
const std::string CIRCLE_REGEX = "CIRCLE: C=(.+),(.+); R=(.+)";

const std::string TRIANGLE = "TRIANGLE: ";
const std::string RECTANGLE = "RECTANGLE: ";
const std::string CIRCLE = "CIRCLE: ";

const std::string PERIMETER = "P=";
const std::string SQUARE = "; S=";

const int WIDTH = 1024;
const int HEIGHT = 768;
const std::string NAME = "Lab2";

CShapeProcess::CShapeProcess(std::string inputName, std::string outputName)
{
	this->m_input.open(inputName);
	this->m_output.open(outputName);
}

void CShapeProcess::ReadShapes()
{
    std::string line;

    while (std::getline(this->m_input, line))
    {
        if (line.find(TRIANGLE) != std::string::npos)
        {
            std::regex re(TRIANGLE_REGEX);
            std::smatch match;

            std::regex_search(line, match, re);

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

            this->m_shapes.push_back(triangle);
        }
        else if (line.find(RECTANGLE) != std::string::npos)
        {
            std::regex re(RECTANGLE_REGEX);
            std::smatch match;

            std::regex_search(line, match, re);

            float x1 = std::stof(match[1]);
            float y1 = std::stof(match[2]);
            float x2 = std::stof(match[3]);
            float y2 = std::stof(match[4]);

            float w = std::abs(x1 - x2);
            float h = std::abs(y1 - y2);

            sf::RectangleShape* rectangle = new sf::RectangleShape();

            rectangle->setSize(sf::Vector2f(w, h));
            rectangle->setPosition(sf::Vector2f(x1, y1));

            this->m_shapes.push_back(rectangle);
        }
        else if (line.find(CIRCLE) != std::string::npos)
        {
            std::regex re(CIRCLE_REGEX);
            std::smatch match;

            std::regex_search(line, match, re);

            float x = std::stof(match[1]);
            float y = std::stof(match[2]);
            float radius = std::stof(match[3]);

            sf::CircleShape* circle = new sf::CircleShape();

            circle->setRadius(radius);
            circle->setPosition(x - radius, y - radius);

            this->m_shapes.push_back(circle);
        }
    }
}


void CShapeProcess::WriteResults()
{
    for (sf::Shape* shape : this->m_shapes)
    {
        CShapeDecorator* shapeDecorator;
        if (dynamic_cast<sf::CircleShape*>(shape))
        {
            shapeDecorator = new CCircleDecorator(shape);
            this->m_output << CIRCLE << PERIMETER << shapeDecorator->GetPerimeter() << SQUARE << shapeDecorator->GetArea() << std::endl;
        }
        else if (dynamic_cast<sf::RectangleShape*>(shape))
        {
            shapeDecorator = new CRectangleDecorator(shape);
            this->m_output << RECTANGLE << PERIMETER << shapeDecorator->GetPerimeter() << SQUARE << shapeDecorator->GetArea() << std::endl;
        }
        else if (dynamic_cast<sf::ConvexShape*>(shape))
        {
            shapeDecorator = new CTriangleDecorator(shape);
            this->m_output << TRIANGLE << PERIMETER << shapeDecorator->GetPerimeter() << SQUARE << shapeDecorator->GetArea() << std::endl;
        }
    }
}

void CShapeProcess::DisplayShapes()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), NAME);

    for (sf::Shape* shape : this->m_shapes)
    {
        window.draw(*shape);
    }

    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
