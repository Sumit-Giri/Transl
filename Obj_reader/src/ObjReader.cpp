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
    int vertexindex = 0;
    while (getline(inputfile, line)) // Reading the file
    {
        if (line.find("v") != string::npos) // Taking inputs of v as vertices
        {
            double x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            if (keyword == "v")
            {

                Point3D P1(x, y, z);

                points.push_back(P1);
            }
        }

        if (line.find("f") != string::npos) // Checking the face values
        {
            string x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            if (keyword == "f")
            {

                int v1, v2, v3; // converting string into int using ASCII
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

    triangulation.triangles() = triangles;
    triangulation.uniquePoints() = points;

    inputfile.close();
}