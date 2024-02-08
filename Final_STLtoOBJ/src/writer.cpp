
#include "../headers/writer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;
writer ::writer()
{
}
writer ::~writer()
{
}
void writer ::writerStl(Triangulation &triangulation)
{

    ofstream outFile("cube.obj");

    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }

    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Point3D> &Normal = triangulation.uniqueNormal();
    vector<Triangle> &triangles = triangulation.triangles();

    // Writing UniqueVertexes into Obj File from UniquePoints Vector
    for (size_t i = 0; i < points.size(); i++)
    {
        outFile << "v"
                << " " << points[i].x() << " " << points[i].y() << " " << points[i].z() << endl;
    }

    // Writing facet into Obj File from Triangles Vector

    for (int i = 0; i < Normal.size(); i++)
    {
        outFile << "vn"
                << " " << Normal[i].x() << " " << Normal[i].y() << " " << Normal[i].z() << endl;
    }

    for (const Triangle &triangle : triangles)
    {

        outFile << "f"
                << " " << triangle.v1() << "//" << triangle.normalOfTriangle() + 1
                << " " << triangle.v2() << "//" << triangle.normalOfTriangle() + 1
                << " " << triangle.v3() << "//" << triangle.normalOfTriangle() + 1 << endl;
    }
    outFile.close();
}