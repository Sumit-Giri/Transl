
#include "../headers/StlToObj.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;

void StlToObj ::writer(Triangulation &triangulation)
{

    ofstream outFile("cube.obj");

    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }

    vector<Point3D> &points = triangulation.uniquePoints();
   //Writing UniqueVertexes into Obj File from UniquePoints Vector
    for (size_t i = 0; i < points.size(); i++)
    {
        outFile << "v"
                << " " << points[i].x() << " " << points[i].y() << " " << points[i].z() << endl;
    }

    vector<Triangle> &triangles = triangulation.triangles();

    //Writing facet into Obj File from Triangles Vector
    int countVertex = 1;
    for (const Triangle &triangle : triangles)
    {

        outFile << "f"
                << " " << triangle.v1() << "/_/_"
                << " " << triangle.v2() << "/_/_"
                << " " << triangle.v3() << "/_/_" << endl;
    }
    outFile.close();
}