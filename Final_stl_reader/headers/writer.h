#pragma once
#include "../headers/Triangulation.h"
class writer
{
    public:
    writer();
    ~writer();
    void  writerStl(Triangulation &triangulation);

};