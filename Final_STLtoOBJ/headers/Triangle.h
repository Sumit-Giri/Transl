#pragma once
#include "Point3D.h"
#include "Shape.h"

class Triangle
{
public:
    Triangle();
    Triangle(Point3D p1, Point3D p2, Point3D p3);
    Triangle(int v1,int v2 ,int v3);
    ~Triangle();
    Point3D pointP1();
    Point3D pointP2();
    Point3D pointP3();
    void setPointP1(Point3D p1);
    void setPointP2(Point3D p2);
    void setPointP3(Point3D p3);
    const int v1() const;
    const int v2() const;
    const int v3() const;

private:
    int mV1;
    int mV2;
    int mV3;
    Point3D mPointP1;
    Point3D mPointP2;
    Point3D mPointP3;
};
