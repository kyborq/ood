#include <string>

#include "CShapeProcess.h"

int main()
{
    CShapeProcess shapeProcess = CShapeProcess("input.txt", "output.txt");

    shapeProcess.ReadShapes();
    shapeProcess.WriteResults();
    shapeProcess.DisplayShapes();

    return 0;
}