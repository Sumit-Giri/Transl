#include "..\headers\Triangulation.h"
#include<map>
#include<vector>
#include<iostream>


Triangulation::Triangulation()
{

}
Triangulation::~Triangulation()
{
    
}

vector<Triangle> & Triangulation::triangles()
{
    return mTriangles;
}
vector<Triangle> & Triangulation::normalTrinangles()
{
    return nNormal;
}

vector<Point3D> & Triangulation::uniquePoints()
{
    return mUniquePoints;
}
 vector<Point3D> & Triangulation :: uniqueNormal()
{
    return mUniqueNormals;
}