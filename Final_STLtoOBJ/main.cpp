// #include <fstream>
// #include <iostream>
// #include <cmath>
// #include "./headers/reader.h"
// #include "./headers/writer.h"

// using namespace std;

// int main()
// {
//   // created object of StlReader
//   reader st;

//   // created object of Triangulation
//   Triangulation triangualtion;
//   st.readFile1(triangualtion);

//   // created object of StlObj
//   writer obj;
//   obj.writerStl(triangualtion);
//   return 0;
// }
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Structure for 3D point
struct Point {
    double x, y, z;
};

// Structure for representing a triangle (facet in STL)
struct Triangle {
    Point p1, p2, p3;
};

// Function to read vertices and triangles from an STL file
void readSTL(const string& filename, vector<Point>& vertices, vector<Triangle>& triangles) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Error: Unable to open input file.");
    }

    // Skip the header
    file.seekg(80);

    // Read the number of triangles
    int numTriangles;
    file.read(reinterpret_cast<char*>(&numTriangles), sizeof(numTriangles));

    // Read each triangle
    for (int i = 0; i < numTriangles; ++i) {
        Triangle triangle;
        // Read normal vector (ignored)
        file.seekg(12, ios::cur);
        // Read vertices
        file.read(reinterpret_cast<char*>(&triangle), sizeof(triangle));
        triangles.push_back(triangle);
    }

    file.close();
}

// Function to compute the cross product of two vectors
Point crossProduct(const Point& p1, const Point& p2) {
    return {
        p1.y * p2.z - p1.z * p2.y,
        p1.z * p2.x - p1.x * p2.z,
        p1.x * p2.y - p1.y * p2.x
    };
}

// Function to compute the dot product of two vectors
double dotProduct(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

// Function to compute the convex hull using the Gift Wrapping algorithm
vector<Point> convexHull(const vector<Point>& points) {
    // There must be at least 3 points
    if (points.size() < 3) {
        throw invalid_argument("Convex hull not possible. Need at least 3 points.");
    }

    vector<Point> hull;
    vector<bool> used(points.size(), false);

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }

    int p = leftmost, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % points.size();
        for (int i = 0; i < points.size(); ++i) {
            if (!used[i] && (q == p || crossProduct(
                {points[i].x - points[p].x, points[i].y - points[p].y, points[i].z - points[p].z},
                {points[q].x - points[p].x, points[q].y - points[p].y, points[q].z - points[p].z}).z > 0)) {
                q = i;
            }
        }
        p = q;
        used[p] = true;
    } while (p != leftmost);

    return hull;
}

// Function to write points to a text file
void writePointsToFile(const vector<Point>& points, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Unable to open output file.");
    }

    for (const auto& p : points) {
        file << p.x << " " << p.y << " " << p.z << endl;
    }

    file.close();
}

int main() {
    string inputFilename = "D://Sumit_Workspace//MergeSTLandOBJ//Final_STLtoOBJ//cube.stl.stl"; // Input STL filename
    string outputFilename = "output.txt"; // Output text filename

    vector<Point> vertices;
    vector<Triangle> triangles;

    try {
        // Read vertices and triangles from the input STL file
        readSTL(inputFilename, vertices, triangles);

        // Extract unique vertices from triangles
        vector<Point> uniqueVertices;
        for (const auto& triangle : triangles) {
            uniqueVertices.push_back(triangle.p1);
            uniqueVertices.push_back(triangle.p2);
            uniqueVertices.push_back(triangle.p3);
        }

        // Compute the convex hull of the unique vertices
        vector<Point> hull = convexHull(uniqueVertices);

        // Write the convex hull vertices to the output text file
        writePointsToFile(hull, outputFilename);

        cout << "Convex hull vertices written to " << outputFilename << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
