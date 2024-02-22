#include "../headers/reader.h"
#include "../headers/Triangulation.h"
#include "../headers/Triangle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


Reader :: Reader()
{

}
Reader :: ~Reader()
{

}
void Reader::readObj(Triangulation &triangulation)
{
   
    ifstream inputfile("Cube.obj");
    string line;

    while (getline(inputfile, line))
    {
        // checking if v is present in line string
        if (line.find("v") != string::npos)
        {
            double x, y, z;
            istringstream vertexStream(line);
            string token;
            vertexStream >> token >> x >> y >> z;
            // checking if v is present in Keyword string
            if (token == "v")
            {

                Point3D P1(x, y, z);

                triangulation.uniquePoints().push_back(P1);
            }
        }
        

        if(line.find("vn")!=string :: npos)
        {
            double x,y,z;
            istringstream vertexNormal(line);
            string token;

            vertexNormal >> token >> x>>y>>z;
            if(token =="vn")
            {
                Point3D Vn(x,y,z);

                
                triangulation.uniqueNormal().push_back(Vn);


            }
        }
        
      

        // checking if f is present in line String
        if (line.find("f") != string::npos)
        {
            string x, y, z;
            istringstream facetline(line);
            string token;
            facetline >> token >> x >> y >> z;

            // checking if f is present in Keyword String
            int v1;
            int v2;
            int v3;
            

            if (token == "f")
            {

                for (int i = 0; i < x.size(); i++)
                {
                    if (x[i] == '/' && i>0)
                    {
                        
                        v1 = stoi(x.substr(0, i));                                   
                        break;
                    }
                }
                for (int i = 0; i < y.size(); i++)
                {
                    if (y[i] == '/' && i>0)
                    {
                        
                        v2 = stoi(y.substr(0, i));                                   
                        break;
                    }
                }
                for (int i = 0; i < z.size(); i++)
                {
                    if (z[i] == '/' && i>0)
                    {
                        
                        v3 = stoi(z.substr(0, i));                                   
                        break;
                    }
                }
                
              
            }
          

            if(token=="f")
            {
                int vn1;

                for(int i=x.size();i>0;i--)
                {
                    if(x[i]=='/' )
                    {
                        vn1=stoi(x.substr(i+1,x.size()-i-1));
                        
                         break;

                    }
                }
                
                Triangle T2(v1-1,v2-1,v3-1,vn1-1);
                triangulation.triangles().push_back(T2);

            }
          



        }
         
    }

    // copied all data of local triangles vector into triangulation
  

   
    inputfile.close();
}