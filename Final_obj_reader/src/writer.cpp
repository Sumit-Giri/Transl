#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/writer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Writer ::Writer()
{
}

Writer ::~Writer()
{
}
void Writer::writeOBJ(Triangulation &triangulation)
{
    std::ofstream outFile("cube.stl");

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    vector<Point3D> &points = triangulation.uniquePoints();

    vector<Triangle> &triangles = triangulation.triangles();
    vector<Point3D> &Normal = triangulation.uniqueNormal();

    // Writing Obj to Stl in STL file Format

    for (const Triangle &triangle : triangles)
    {

        outFile << points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
        outFile << points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << endl;
        outFile << points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << endl;
    }

    outFile.close();
}