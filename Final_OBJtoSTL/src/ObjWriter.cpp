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
    std::ofstream outFile("Cube1.stl");

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    vector<Point3D> &points = triangulation.uniquePoints();

    vector<Triangle> &triangles = triangulation.triangles();

    //Writing Obj to Stl in STL file Format
    outFile <<"solid exported "<<endl;
    for (const Triangle &triangle : triangles)
    {

        
        outFile <<"    "<<"facet normal 0 0 0" <<endl;
        outFile<<"      "<<"outer loop" <<endl;
        outFile <<"         " <<"vertex "<<points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile <<"         " <<"vertex "<< points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile <<"         " <<"vertex "<< points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;
        outFile<<"      "<<"endloop" <<endl;
        outFile<<"     "<<"endfacet" <<endl;

       
    }
    outFile <<"End "<<endl;
    outFile.close();
}