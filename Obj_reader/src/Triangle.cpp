#include "../headers/Triangle.h"

Triangle::Triangle() : mV1(), mV2(), mV3() {}

Triangle::Triangle(int v1, int v2, int v3)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
}

const int Triangle::v1() const
{
    return mV1;
}

const int Triangle::v2() const
{
    return mV2;
}

const int Triangle::v3() const
{
    return mV3;
}

void Triangle::setV1(const int v1)
{
    mV1 = v1;
}

void Triangle::setV2(const int v2)
{
    mV2 = v2;
}

void Triangle::setV3(const int v3)
{
    mV3 = v3;
}