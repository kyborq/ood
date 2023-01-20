#pragma once
#include <regex>
#include <SFML/Graphics.hpp>

#include "CShapeDecorator.h"

class CShapeCreator
{
public:
	virtual CShapeDecorator* CreateShape(std::smatch& match) = 0;
};