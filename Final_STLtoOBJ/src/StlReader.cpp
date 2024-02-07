#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "../headers/Point3D.h"
#include "../headers/StlReader.h"
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"

using namespace std;

StlReader ::StlReader()
{
}
StlReader ::~StlReader()
{
}

void StlReader ::readFile1(Triangulation &triangualtion)
{
    std::ifstream readFromFile("cube.stl");

    vector<Triangle> vertexData;
    vector<Point3D> different;
    map<Point3D, int> mp;
    string line;
    vector<Triangle> tri;

    if (readFromFile.is_open())
    {

        int count = 1;
        int v1;
        int v2;
        int v3;
        while (getline(readFromFile, line))
        {

            if (line.find("vertex") != std::string::npos)
            {
                istringstream iss(line);
                string keyword;
                double x, y, z;

                iss >> keyword >> x >> y >> z;
                //Stored Coordinates x,y,z into object of Point3D
                Point3D point(x, y, z);
                
                auto it = mp.find(point);

                if (it == mp.end())
                {
                    different.push_back(point);

                    mp[point] = different.size();
                }
                if (count == 1)
                {
                    v1 = mp[point];
                    count++;
                }
                else if (count == 2)
                {
                    v2 = mp[point];
                    count++;
                }
                else if (count == 3)
                {

                    v3 = mp[point];
                    count++;
                }

                if (count == 4)
                {
                    cout << tri.size() << " "
                         << "tri";
                    Triangle T(v1, v2, v3);
                    tri.push_back(T);
                    count = 1;
                }
            }
        }
        //copied all data of tri into triangles
        triangualtion.triangles() = tri;
        //copied all data of different vector into uniquePoints
        triangualtion.uniquePoints() = different;
        readFromFile.close();
    }
    else
    {
        std::cerr << "Error opening files!" << std::endl;
    }
}
