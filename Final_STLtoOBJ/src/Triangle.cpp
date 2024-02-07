
#include "../headers/Triangle.h"

using namespace std;

Triangle ::Triangle()
{
}
Triangle ::Triangle(Point3D p1, Point3D p2, Point3D p3)
{
    mPointP1 = p1;
    mPointP2 = p2;
    mPointP3 = p3;
}
Triangle ::~Triangle()
{
}

Point3D Triangle ::pointP1()
{
    return mPointP1;
}
Point3D Triangle ::pointP2()
{
    return mPointP2;
}
Point3D Triangle ::pointP3()
{
    return mPointP3;
}

void Triangle ::setPointP1(Point3D p1)
{
    mPointP1 = p1;
}
void Triangle ::setPointP2(Point3D p2)
{
    mPointP2 = p2;
}
void Triangle ::setPointP3(Point3D p3)
{
    mPointP3 = p3;
}

const int Triangle ::v1() const
{
    return mV1;
}

const int Triangle ::v2() const
{
    return mV2;
}

const int Triangle ::v3() const
{
    return mV3;
}

Triangle ::Triangle(int v1, int v2, int v3)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
}