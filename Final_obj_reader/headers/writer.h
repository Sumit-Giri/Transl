#pragma once
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"

class Writer
{
public:
    Writer();
    ~Writer();
    void writeOBJ(Triangulation &triangulation);
};