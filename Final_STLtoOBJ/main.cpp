#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/StlReader.h"
#include "./headers/StlToObj.h"

using namespace std;

int main()
{
  // created object of StlReader
  StlReader st;

  // created object of Triangulation
  Triangulation triangualtion;
  st.readFile1(triangualtion);

  // created object of StlObj
  StlToObj obj;
  obj.writer(triangualtion);
  return 0;
}
