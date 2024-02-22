#pragma once
#include "Triangulation.h"

class reader
{
public:
    reader();
    ~reader();
    void readObj(Triangulation &triangulation);
};