#pragma once
#include "Triangulation.h"

class Reader
{
public:
    Reader();
    ~Reader();
    void readObj(Triangulation& triangulation);
};