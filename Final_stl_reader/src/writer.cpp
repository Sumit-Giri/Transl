
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

    ofstream outFile("cube.txt");

    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }

    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Point3D> &Normal = triangulation.uniqueNormal();
    vector<Triangle> &triangles = triangulation.triangles();

    

    for (const Triangle &triangle : triangles)
    {
        // Write each vertex of the triangle to the STL file
        outFile <<points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
        outFile <<points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << endl;
        outFile <<points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << endl;
    }
    outFile.close();
}