#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include"Shape.h"
#include<iostream>
using namespace std;

class Rectangle : public Shape
{
    private:
        int width;
        int height;

    public:
        Rectangle(int x, int y, int w, int h);
        void draw();
        double getArea() const;
};

#endif