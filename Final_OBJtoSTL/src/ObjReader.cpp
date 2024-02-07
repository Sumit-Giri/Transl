#include "../headers/ObjReader.h"
#include "../headers/Triangulation.h"
#include "../headers/Triangle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

void ObjReader::readObj(Triangulation &triangulation)
{
    vector<Point3D> points;
    vector<Triangle> triangles;

    ifstream inputfile("Cube.obj");
    string line;

    while (getline(inputfile, line))
    {
        //checking if v is present in line string
        if (line.find("v") != string::npos)
        {
            double x, y, z;
            istringstream singleline(line);
            string keyword;
            singleline >> keyword >> x >> y >> z;
            //checking if v is present in Keyword string
            if (keyword == "v")
            {

                Point3D P1(x, y, z);

                points.push_back(P1);
            }
        }

        //checking if f is present in line String
        if (line.find("f") != string::npos)
        {
            string x, y, z;
            istringstream singleLine(line);
            string keyword;
            singleLine >> keyword >> x >> y >> z;

            //checking if f is present in Keyword String
            if (keyword == "f")
            {

                int v1, v2, v3;
                v1 = x[0];
                v1 -= 48;
                v2 = y[0];
                v2 -= 48;
                v3 = z[0];
                v3 -= 48;

                Triangle T(v1, v2, v3);
                triangles.push_back(T);
            }
        }
    }

    //copied all data of local triangles vector into triangulation
    triangulation.triangles() = triangles;

    //copied all data of Points vector into uniquePoints
    triangulation.uniquePoints() = points;

    inputfile.close();
}