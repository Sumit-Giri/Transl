#pragma once
#include <vector>
#include "Triangle.h"
using namespace std;

class Triangulation
{
public:
    Triangulation();
    ~Triangulation();

    vector<Triangle> &triangles();
    vector<Point3D> &uniquePoints();
    void printtriangles();

private:
    vector<Triangle> mTriangles;
    vector<Point3D> mUniquePoints;
};
