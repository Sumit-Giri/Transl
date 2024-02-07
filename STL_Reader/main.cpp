#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/StlReader.h"
#include "./headers/STLwriter.h"

using namespace std;

int main()
{
  //created object of STLReader
  StlReader st;
  //created object of triangulation
  Triangulation triangualtion;
  st.readFile1(triangualtion);

  //created object of STLWriter
  STLwriter obj;
  obj.writeSTLToFile(triangualtion);
  return 0;
}
