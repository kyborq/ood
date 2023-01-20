#pragma once
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"

class IVisitor
{
public:
    virtual ~IVisitor() = default;
    virtual std::string VisitShape(const CCircleDecorator&) = 0;
    virtual std::string VisitShape(const CRectangleDecorator&) = 0;
    virtual std::string VisitShape(const CTriangleDecorator&) = 0;
};