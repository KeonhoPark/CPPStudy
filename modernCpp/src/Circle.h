#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include"Shape.h"
#include<iostream>
using namespace std;

class Circle : public Shape
{
    private:
        double radius;

    public:
        Circle(int x, int y, int r);
        void draw();
        double getArea() const;
};

#endif