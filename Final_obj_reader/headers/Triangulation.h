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
    vector<Triangle> &normalTrinangles();
    vector<Point3D> &uniquePoints();
    vector<Point3D> &uniqueNormal();
    void printtriangles();

private:
    vector<Triangle> mTriangles;
     vector<Triangle> nNormal;
    vector<Point3D> mUniquePoints;
    vector<Point3D>mUniqueNormals;
};
