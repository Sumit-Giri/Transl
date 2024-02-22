#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/reader.h"
#include "./headers/writer.h"

using namespace std;

int main()
{
  // created object of StlReader
  reader st;

  // created object of Triangulation
  Triangulation triangualtion;
  st.readFile1(triangualtion);

  // created object of StlObj
  writer obj;
  obj.writerStl(triangualtion);
  return 0;
}
