#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/ObjWriter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void ObjWriter::writeOBJ(Triangulation &triangulation)
{
    std::ofstream outFile("Cube1.txt");

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }
    // copied uniquePoints into points
    vector<Point3D> &points = triangulation.uniquePoints();

    // copied local trianles  into triangles
    vector<Triangle> &triangles = triangulation.triangles();

    // writing obj into txt file
    for (const Triangle &triangle : triangles)
    {

        outFile << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;
    }
    outFile.close();
}