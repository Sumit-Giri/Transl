#include <iostream>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/ObjReader.h"
#include "./headers/ObjWriter.h"
using namespace std;

int main()
{
    //created object of ObjReader
    ObjReader reader;

    //created object of Triangulation
    Triangulation tri;

    //created object of ObjWriter
    ObjWriter writer;
    writer.writeOBJ(tri);
    return 0;
}