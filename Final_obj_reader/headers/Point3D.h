#pragma once

class Point3D
{
public:
    Point3D();
    Point3D(double inX, double inY, double inZ);
    ~Point3D();

    double x() const;
    double y() const;
    double z() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    bool operator<(const Point3D &other) const;

    // bool checkPoint(Point3D p1);
private:
    double mX;
    double mY;
    double mZ;
};