#ifndef __SHAPE_H__
#define __SHAPE_H__
#include<iostream>
using namespace std;

class Shape
{
private:
    int xpos;
    int ypos;

public:
    Shape(int x, int y);
    virtual void draw();
    virtual double getArea() const;
};

#endif