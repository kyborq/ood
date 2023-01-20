#include <string>
#include <regex>

#include "CShapeProcess.h"
#include "CShapeDecorator.h"
#include "CTriangleDecorator.h"
#include "CRectangleDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleCreator.h"
#include "CTriangleCreator.h"
#include "CCircleCreator.h"
#include "CShapeVisitor.h"

const std::string TRIANGLE_REGEX = "TRIANGLE: P1=(.+),(.+); P2=(.+),(.+); P3:(.+),(.+)";
const std::string RECTANGLE_REGEX = "RECTANGLE: P1=(.+),(.+); P2=(.+),(.+)";
const std::string CIRCLE_REGEX = "CIRCLE: C=(.+),(.+); R=(.+)";

const std::string TRIANGLE = "TRIANGLE: ";
const std::string RECTANGLE = "RECTANGLE: ";
const std::string CIRCLE = "CIRCLE: ";

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

            CTriangleCreator creator;
            auto triangle = creator.CreateShape(match);

            this->m_shapes.push_back(triangle);
        }
        else if (line.find(RECTANGLE) != std::string::npos)
        {
            std::regex re(RECTANGLE_REGEX);
            std::smatch match;

            std::regex_search(line, match, re);

            CRectangleCreator creator;
            auto rectangle = creator.CreateShape(match);

            this->m_shapes.push_back(rectangle);
        }
        else if (line.find(CIRCLE) != std::string::npos)
        {
            std::regex re(CIRCLE_REGEX);
            std::smatch match;

            std::regex_search(line, match, re);

            CCircleCreator creator;
            auto circle = creator.CreateShape(match);

            this->m_shapes.push_back(circle);
        }
    }
}


void CShapeProcess::WriteResults()
{
    // for (auto shape : this->m_shapes)
    // {
    //     this->m_output << shape->ToString() << std::endl;
    // }
    CShapeVisitor visitor;
	for (const auto& shape : m_shapes)
	{
		m_output << shape->Accept(visitor) << std::endl;
	}
}

void CShapeProcess::DisplayShapes()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), NAME);

    for (auto shape : this->m_shapes)
    {
        shape->Display(window);
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
