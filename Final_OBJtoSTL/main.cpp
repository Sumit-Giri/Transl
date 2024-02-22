#include <iostream>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/reader.h"
#include "./headers/writer.h"
using namespace std;

int main()
{
    //created object of ObjReader
    Triangulation tri;
    reader Reader;

    Reader.readObj(tri);

    //created object of Triangulation
    

    //created object of ObjWriter
    writer Writer;
    Writer.writeOBJ(tri);
    return 0;
}