#include "../headers/Point3D.h"

Point3D::Point3D() : mX(0), mY(0), mZ(0) {}

Point3D::Point3D(double inX, double inY, double inZ) : mX(inX), mY(inY), mZ(inZ) {}

double Point3D::x() const
{
    return mX;
}

double Point3D::y() const
{
    return mY;
}

double Point3D::z() const
{
    return mZ;
}

void Point3D ::setX(double x)
{
    mX = x;
}
void Point3D ::setY(double y)
{
    mY = y;
}
void Point3D ::setZ(double z)
{
    mZ = z;
}


//operator overloading
bool Point3D::operator<(const Point3D &other) const
{
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    return mZ < other.mZ;
}
Point3D::~Point3D() {}
