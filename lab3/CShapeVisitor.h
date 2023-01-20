#pragma once
#include "IVisitor.h"

class ShapeVisitor : public IVisitor
{
public:
    std::string VisitShape(const CCircleDecorator&) override;
    std::string VisitShape(const CRectangleDecorator&) override;
    std::string VisitShape(const CTriangleDecorator&) override;
};

