#include <sstream>
#include "CShapeVisitor.h"

std::string ShapeVisitor::VisitShape(const CCircleDecorator& circle)
{
	std::ostringstream stream;

	stream << "CIRCLE: "
		<< "AREA: " << circle.GetArea() << "; "
		<< "PERIMETER: " << circle.GetPerimeter() << " ;";

	return stream.str();
}

std::string ShapeVisitor::VisitShape(const CRectangleDecorator& rectangle)
{
	std::ostringstream stream;

	stream << "RECTANGLE: "
		<< "AREA: " << rectangle.GetArea() << "; "
		<< "PERIMETER: " << rectangle.GetPerimeter() << " ;";

	return stream.str();
}

std::string ShapeVisitor::VisitShape(const CTriangleDecorator& triangle)
{
	std::ostringstream stream;

	stream << "TRIANGLE: "
		<< "AREA: " << triangle.GetArea() << "; "
		<< "PERIMETER: " << triangle.GetPerimeter() << " ;";

	return stream.str();
}
