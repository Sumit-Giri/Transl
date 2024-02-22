#pragma once
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"

class writer
{
public:
    writer();
    ~writer();
    void writeOBJ(Triangulation &triangulation);
};