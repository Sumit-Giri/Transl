// STLWriter.cpp
#include "../headers/STLwriter.h"
#include "../headers/Triangulation.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void STLwriter ::writeSTLToFile(Triangulation &triangulationObj)
{
    std::ofstream outFile("outputCube.txt");

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }
    //copied uniquePoints into points 
    vector<Point3D> &points = triangulationObj.uniquePoints();
    //copied triangles data into trianngles vector
    vector<Triangle> &triangles = triangulationObj.triangles();
    //writing all trinagles from Triangles vector and stored in into txt file
    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
        outFile << points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << endl;
        outFile << points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << endl;
    }
    outFile.close();
}