#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <fstream>
#include <vector>

#include "CShapeDecorator.h"

class CShapeProcess
{
public:
	CShapeProcess(std::string inputName, std::string outputName);

	void ReadShapes();
	void WriteResults();

	void DisplayShapes();
private:
	std::ifstream m_input;
	std::ofstream m_output;
	std::vector<CShapeDecorator*> m_shapes;
};

