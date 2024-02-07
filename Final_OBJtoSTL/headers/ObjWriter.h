#pragma once
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"

class ObjWriter
{
public:
    void writeOBJ(Triangulation &triangulation);
};